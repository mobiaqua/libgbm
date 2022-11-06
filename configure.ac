#
#  Copyright 2005 Red Hat, Inc.
#
#  Permission to use, copy, modify, distribute, and sell this software and its
#  documentation for any purpose is hereby granted without fee, provided that
#  the above copyright notice appear in all copies and that both that
#  copyright notice and this permission notice appear in supporting
#  documentation, and that the name of Red Hat not be used in
#  advertising or publicity pertaining to distribution of the software without
#  specific, written prior permission.  Red Hat makes no
#  representations about the suitability of this software for any purpose.  It
#  is provided "as is" without express or implied warranty.
#
#  RED HAT DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
#  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
#  EVENT SHALL RED HAT BE LIABLE FOR ANY SPECIAL, INDIRECT OR
#  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
#  DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
#  TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
#  PERFORMANCE OF THIS SOFTWARE.
#

# Initialize Autoconf
AC_PREREQ([2.60])
AC_INIT([libgbm], [22.4.0], [https://www.mesa3d.org], [libgbm])
AC_CONFIG_SRCDIR([Makefile.am])
AC_CONFIG_HEADERS([config.h])

# Initialize Automake
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE

dnl find a compiler
AC_PROG_CC

# Initialize libtool
AC_PROG_LIBTOOL

dnl Check for pkgconfig first
AC_CHECK_PROG([HAVE_PKGCONFIG], [pkg-config], [yes], [no])

dnl *** checks for libraries ***
dnl Check for libdrm
PKG_CHECK_MODULES(DRM, libdrm)

AC_CONFIG_FILES([Makefile gbm.pc])
AC_OUTPUT
