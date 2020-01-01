lib_LTLIBRARIES = libgbm.la libgbm_pvr.la libpvrws_GBM.la

libgbm_la_SOURCES =	\
	gbm.c		\
	backend.c

libgbm_la_LIBADD =	\
	$(DRM_LIBS)

libgbm_la_CFLAGS =	\
	-D_OS_UNIX=1	\
	-DMODULEDIR='"$(exec_prefix)/lib/gbm"' \
	$(DRM_CFLAGS)

libgbm_la_LDFLAGS = -version-info 1:0:0

extdir = $(includedir)/gbm
ext_HEADERS =		\
	gbm.h		\
	gbmint.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gbm.pc

libgbm_pvr_la_SOURCES=	\
	gbm_pvr.c

libgbm_pvr_la_CFLAGS =	\
	-D_OS_UNIX=1	\
	$(DRM_CFLAGS)

libgbm_pvr_la_LIBADD =	\
	$(DRM_LIBS)

libpvrws_GBM_la_SOURCES=	\
	pvrws_GBM.c

libpvrws_GBM_la_CFLAGS =	\
	-D_OS_UNIX=1	\
	$(DRM_CFLAGS)

libpvrws_GBM_la_LIBADD =	\
	$(DRM_LIBS)
