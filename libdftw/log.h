#ifndef __LIBDFTW_LOG_H
#define __LIBDFTW_LOG_H

#include "libdftw.h"

#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef enum DFTW_loglevel {
    DFTW_LOG_FATAL = 1,
    DFTW_LOG_ERR   = 2,
    DFTW_LOG_WARN  = 3,
    DFTW_LOG_INFO  = 4,
    DFTW_LOG_DBG   = 5
} DFTW_loglevel;

#define LOG(level, ...) do {  \
        if (level <= DFTW_debug_level) { \
            fprintf(DFTW_debug_stream, "%d:%d:%s:%d:", (int)time(NULL), \
                    DFTW_global_rank, __FILE__, __LINE__); \
            fprintf(DFTW_debug_stream, __VA_ARGS__); \
            fprintf(DFTW_debug_stream, "\n"); \
            fflush(DFTW_debug_stream); \
        } \
    } while (0)

extern FILE* DFTW_debug_stream;
extern enum DFTW_loglevel DFTW_debug_level;
extern int32_t DFTW_global_rank;

#endif /* __LIBDFTW_LOG_H */
