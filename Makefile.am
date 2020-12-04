lib_LTLIBRARIES = libgbm.la

libgbm_la_SOURCES =	\
	gbm.c		\
	backend.c

libgbm_la_LIBADD =

libgbm_la_CFLAGS =	\
	-D_OS_UNIX=1	\
	-DMODULEDIR='"$(exec_prefix)/lib/gbm"'

libgbm_la_LDFLAGS = -version-info 20:3:0

extdir = $(includedir)/gbm
ext_HEADERS =		\
	gbm.h		\
	gbmint.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gbm.pc
