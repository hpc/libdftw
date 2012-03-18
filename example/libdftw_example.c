/*
 * An example of using libdftw.
 */

#include "libdftw_example.h"

static int
display_info(const char *fpath, const struct stat *sb, int tflag) {
    fprintf(stdout, "Walking: `%s'\n", fpath);

    printf("%-3s %7jd   %-40s\n",
        (tflag == FTW_D) ?   "d"   : (tflag == FTW_DNR) ? "dnr" :
        (tflag == FTW_NS) ?  "ns"  : (tflag == FTW_F) ?   "f" : "???",
        (intmax_t) sb->st_size, fpath);

    return 0;           /* To tell dftw() to continue */
}

int main(int argc, char **argv)
{
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Walking with root as: `%s'\n", argv[1]);
    dftw(argv[1], display_info);

    exit(EXIT_SUCCESS);
}

/* EOF */
