#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>

int remove(char *name_infile) {
	if (strstr(name_infile, "PROTECT") != NULL) { return 0; }
	
	int (*old_remove)(char *) = dlsym(RTLD_NEXT, "remove");
	return old_remove(name_infile);
}
