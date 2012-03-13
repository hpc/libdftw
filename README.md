libdftw 0.0.1
===============
libdftw is a decentralized and distributed version of a file tree walk function, similiar to ftw(3).

Dependencies
------------
* Libcircle  <http://github.com/hpc/libdftw>

Usage
-----

```
int dftw(const char *dirpath,
         int (*fn) (const char *fpath, const struct stat *sb, int typeflag),
         int flags);
```
