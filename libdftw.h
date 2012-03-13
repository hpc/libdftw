#ifndef __LIBDFTW_H
#define __LIBDFTW_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

enum {
  FTW_F,		/* Regular file.  */
#define FTW_F	 FTW_F
  FTW_D,		/* Directory.  */
#define FTW_D	 FTW_D
  FTW_DNR,		/* Unreadable directory.  */
#define FTW_DNR	 FTW_DNR
  FTW_NS,		/* Unstatable file.  */
#define FTW_NS	 FTW_NS
};

void dftw(const char *dirpath,
        int (*fn) (const char *fpath, const struct stat *sb, int typeflag));

#endif /* __LIBDFTW_H */
