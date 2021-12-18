#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([binsearch], [1.02], [keknow@ya.ru])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN(binsearch)
AC_CONFIG_SRCDIR([binsearch.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([realpath setlocale])

AC_CONFIG_FILES([Makefile Doxyfile])
AC_OUTPUT
