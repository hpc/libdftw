include $(top_srcdir)/common.mk

noinst_PROGRAMS = dftw_test

dftw_test_SOURCES = dftw_test.c
dftw_test_LDADD = $(top_srcdir)/libdftw.la
dftw_test_CPPFLAGS = \
    $(libdftw_CFLAGS) \
    -I$(top_srcdir)/
