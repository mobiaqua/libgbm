/*
 * Copyright (C) 2013 Rob Clark <robclark@freedesktop.org>
 * Copyright (C) 2014-2016 Emil Velikov <emil.l.velikov@gmail.com>
 * Copyright (C) 2016 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Authors:
 *    Rob Clark <robclark@freedesktop.org>
 */

#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#include "loader.h"

/**
 * Opens a driver or backend using its name, returning the library handle.
 *
 * \param driverName - a name like "i965", "radeon", "nouveau", etc.
 * \param lib_suffix - a suffix to append to the driver name to generate the
 * full library name.
 * \param search_path_vars - NULL-terminated list of env vars that can be used
 * \param default_search_path - a colon-separted list of directories used if
 * search_path_vars is NULL or none of the vars are set in the environment.
 * \param warn_on_fail - Log a warning if the driver is not found.
 */
void *
loader_open_driver_lib(const char *driver_name,
                       const char *lib_suffix,
                       const char **search_path_vars,
                       const char *default_search_path,
                       bool warn_on_fail)
{
   char path[PATH_MAX];
   const char *search_paths, *next, *end;

   search_paths = NULL;
   if (geteuid() == getuid() && search_path_vars) {
      for (int i = 0; search_path_vars[i] != NULL; i++) {
         search_paths = getenv(search_path_vars[i]);
         if (search_paths)
            break;
      }
   }
   if (search_paths == NULL)
      search_paths = default_search_path;

   void *driver = NULL;
   const char *dl_error = NULL;
   end = search_paths + strlen(search_paths);
   for (const char *p = search_paths; p < end; p = next + 1) {
      int len;
      next = strchr(p, ':');
      if (next == NULL)
         next = end;

      len = next - p;
      if (driver == NULL) {
         snprintf(path, sizeof(path), "%.*s/%s%s.so", len,
                  p, driver_name, lib_suffix);
         driver = dlopen(path, RTLD_NOW | RTLD_GLOBAL);
         if (driver == NULL) {
            dl_error = dlerror();
            fprintf(stderr, "failed to open %s: %s\n", path, dl_error);
         }
      }
      /* not need continue to loop all paths once the driver is found */
      if (driver != NULL)
         break;
   }

   if (driver == NULL) {
      if (warn_on_fail) {
         fprintf(stderr, "failed to open %s: %s (search paths %s, suffix %s)\n",
                 driver_name, dl_error, search_paths, lib_suffix);
      }
      return NULL;
   }

   return driver;
}
