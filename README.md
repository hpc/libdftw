libdftw
=======
libdftw is a decentralized and distributed filesystem file treewalk function, similiar to ftw(3).

Dependencies
------------
* [Libcircle](http://github.com/hpc/libcircle)

Usage
-----

```
void dftw(const char *dirpath,
         int (*fn) (const char *fpath, const struct stat *sb, int typeflag))
```

### RPM Creation
First, check the [![Build Status](https://travis-ci.org/hpc/libdftw.png?branch=master)](https://travis-ci.org/hpc/libdftw). If all tests are passing, create an rpm using the following instructions:

1. ```rpmbuild -ta libdftw-<version>.tar.gz```
2. ```rpm --install <the appropriate RPM files>```

### Contributions
Please view the *HACKING.md* file for more information on how to contribute to dcp.

### COPYING
See the included *COPYING* file for additional information.
