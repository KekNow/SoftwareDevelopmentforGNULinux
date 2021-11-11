#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([rhasher.c], [1.0], [keknow@ya.ru])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign subdir-objects])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([rhash],[rhash_library_init],[],[AC_MSG_ERROR([library not found])])
AC_CHECK_LIB([readline],[readline],[],[])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_ARG_ENABLE(
	[readline],
	AS_HELP_STRING([--enable-readline], [Readline activate]),
	AC_DEFINE(READLINE_FLAG,[1],[Readline activate]),
	[readline_mode="deactivate"]
  )
AS_IF([test "x$readline_mode" = "xdeactivate"], [
    AC_SUBST(LIBS, ["-lrhash"])
])

# Checks for library functions.
AC_CHECK_FUNCS([strcasecmp strerror])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
