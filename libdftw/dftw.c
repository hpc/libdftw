#include <stdlib.h>
#include <libcircle.h>

#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "log.h"
#include "dftw.h"

/** The debug stream for all logging messages. */
FILE* DFTW_debug_stream;

/** The current log level of library logging output. */
enum DFTW_loglevel DFTW_debug_level;

/** The rank value of the current node. */
int32_t DFTW_global_rank;

/** The top directory specified. */
char _DFTW_TOP_DIR[PATH_MAX];

/** The callback. */
DFTW_cb_t _DFTW_CB;

/** Call back given to initialize the dataset. */
void DFTW_create(CIRCLE_handle* handle)
{
    handle->enqueue(_DFTW_TOP_DIR);
}

/** Callback given to process the dataset. */
void DFTW_process(CIRCLE_handle* handle)
{
    struct stat st;
    int status = 0;

    char temp[CIRCLE_MAX_STRING_LEN];
    handle->dequeue(temp);

    LOG(DFTW_LOG_DBG, "Popped [%s]", temp);

    /* Try and stat it, checking to see if it is a link */
    status = lstat(temp, &st);

    if(status != EXIT_SUCCESS) {
        LOG(DFTW_LOG_ERR, "Error: Couldn't stat \"%s\"", temp);
    }

    else if(S_ISDIR(st.st_mode) && !(S_ISLNK(st.st_mode))) {
        _DFTW_CB(temp, &st, FTW_D);
        DFTW_process_dir(temp, handle);
    }
    else if(S_ISREG(st.st_mode)) {
        _DFTW_CB(temp, &st, FTW_F);
    }

}

void DFTW_process_dir(char* dir, CIRCLE_handle* handle)
{
    DIR* current_dir;
    struct dirent* current_ent;
    char parent[CIRCLE_MAX_STRING_LEN];

    current_dir = opendir(dir);

    if(!current_dir) {
        LOG(DFTW_LOG_ERR, "Unable to open dir: %s", dir);
    }
    else {
        /* Read in each directory entry */
        while((current_ent = readdir(current_dir)) != NULL) {
            /* We don't care about . or .. */
            if((strncmp(current_ent->d_name, ".", 2)) && (strncmp(current_ent->d_name, "..", 3))) {
                strcpy(parent, dir);
                strcat(parent, "/");
                strcat(parent, current_ent->d_name);

                LOG(DFTW_LOG_DBG, "Pushing [%s] <- [%s]", parent, dir);

                handle->enqueue(parent);
            }
        }
    }

    closedir(current_dir);

    return;
}

void dftw(const char* dirpath,
          int (*fn)(const char* fpath, const struct stat* sb, int typeflag))
{

    _DFTW_CB = fn;

    strncpy(_DFTW_TOP_DIR, dirpath, PATH_MAX);
    CIRCLE_init(0, NULL, CIRCLE_DEFAULT_FLAGS);

    CIRCLE_cb_create(&DFTW_create);
    CIRCLE_cb_process(&DFTW_process);

    CIRCLE_begin();
    CIRCLE_finalize();
}

/* EOF */
