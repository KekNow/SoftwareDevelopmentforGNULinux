TESTS = grow_test init_test noop_test pop_test push_test
check_PROGRAMS = grow_test init_test noop_test pop_test push_test

CFLAGS = -I$(top_builddir)/src @CHECK_CFLAGS@
LDADD = $(top_builddir)/src/libbuf.la @CHECK_LIBS@

.ts.c:
	checkmk $< > $@
