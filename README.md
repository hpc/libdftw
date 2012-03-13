libdftw 0.0.1
===============
libdftw is a decentralized and distributed filesystem file treewalk function, similiar to ftw(3).

Dependencies
------------
* [Libcircle](http://github.com/hpc/libcircle)

Usage
-----

```
int dftw(const char *dirpath,
         int (*fn) (const char *fpath, const struct stat *sb, int typeflag))
```
