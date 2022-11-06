lib_LTLIBRARIES = libgbm.la

libgbm_la_SOURCES =	\
	gbm.c		\
	backend.c	\
	loader.c

libgbm_la_LIBADD =

libgbm_la_CFLAGS =	\
	-D_OS_UNIX=1	\
	-DDEFAULT_BACKENDS_PATH='"$(exec_prefix)/lib/gbm"' \
	$(WARN_CFLAGS) $(CFLAGS) $(DRM_CFLAGS)

libgbm_la_LDFLAGS = -no-undefined -version-info 22:4:0

extdir = $(includedir)/gbm
ext_HEADERS =		\
	gbm.h		\
	gbmint.h	\
	gbm_backend_abi.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gbm.pc
