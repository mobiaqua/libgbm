lib_LTLIBRARIES = libgbm.la gbm_pvr.la pvrws_GBM.la

libgbm_la_SOURCES =	\
	gbm.c		\
	backend.c

libgbm_la_LIBADD =

libgbm_la_CFLAGS =	\
	-D_OS_UNIX=1	\
	-DMODULEDIR='"$(exec_prefix)/lib/gbm"'

libgbm_la_LDFLAGS = -version-info 1:0:0

extdir = $(includedir)/gbm
ext_HEADERS =		\
	gbm.h		\
	gbmint.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gbm.pc

gbm_pvr_la_SOURCES=	\
	gbm_pvr.c \
	gbm_pvrint.h

gbm_pv_la_CFLAGS =	\
	-D_OS_UNIX=1

pvrws_GBM_la_SOURCES=	\
	pvrws_GBM.c \
	pvrws_GBM.h

pvrws_GBM_la_CFLAGS =	\
	-D_OS_UNIX=1
