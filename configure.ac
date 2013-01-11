AC_INIT([LibDftw],[0.0.2],[github-hpc@lanl.gov],[libdftw],[http://github.com/hpc/libdftw])

# Keep artifacts in directories as much as possible.
AC_CONFIG_AUX_DIR(auxdir)
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([foreign])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_CONFIG_HEADERS([config.h])

# Check for compilers.
AC_PROG_CC
AM_PROG_CC_C_O

# Check for libcircle
PKG_CHECK_MODULES([libcircle], libcircle)

# Pull in libtool.
LT_INIT

# Checks for typedefs, structs, and compiler options.
AC_TYPE_SIZE_T
AC_C_INLINE

# Checks for library functs.
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_MALLOC
AC_FUNC_LSTAT

# Define the library version.
AC_SUBST([LIBDFTW_SO_VERSION], [0:2:0])
AC_SUBST([LIBDFTW_API_VERSION], [0.0.2])

AC_CONFIG_FILES([Makefile \
                 tests/Makefile \
                 libdftw.pc:libdftw.pc.in])
AC_OUTPUT
