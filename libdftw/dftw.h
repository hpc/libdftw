#ifndef _LIBDFTW_DFTW_H
#define _LIBDFTW_DFTW_H

#include <config.h>
#include <libcircle.h>

#include "libdftw.h"
#include "log.h"

typedef int (*DFTW_cb_t)(const char* fpath, const struct stat* sb, int typeflag);

void DFTW_create(CIRCLE_handle* handle);
void DFTW_process(CIRCLE_handle* handle);
void DFTW_process_dir(char* dir, CIRCLE_handle* handle);

#endif /* _LIBDFTW_DFTW_H */
