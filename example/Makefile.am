include $(top_srcdir)/common.mk

noinst_PROGRAMS = libdftw_example
libdftw_example_SOURCES = libdftw_example.c
libdftw_example_LDADD = \
    $(top_srcdir)/libdftw.la

libdftw_example_CPPFLAGS = \
    $(libdftw_CFLAGS) \
    -I$(top_srcdir)/
