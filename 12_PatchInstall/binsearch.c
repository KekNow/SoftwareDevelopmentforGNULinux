#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <libintl.h>
#include <string.h>

#include "config.h"
#define LOCALE_PATH "../share/locale/"
#define _(STRING) gettext(STRING)

#define MANUAL _("Binsearch using human\n\
\n\
Usage: ./binsearch [OPTIONS] \n\
\n\
    --version   print current version \n\
    --help      print help \n")


int main(int argc, char** argv) {
	setlocale (LC_ALL, "");
	bindtextdomain ("binsearch", LOCALE_PATH);
	textdomain ("binsearch");
	
	if (argc == 2) {
		if (strcmp(argv[1], "--help") == 0) {
			return printf(MANUAL);
		}
		else if (strcmp(argv[1], "--version") == 0) {
			return printf("%s\n", VERSION);
		}
	}

	printf(_("Choose number from [1..100] (in the mind)\n"));
	char response[10];
	int left = 1, right = 100, middle;
	while (left < right) {
		middle = (left + right) / 2;
		printf(_("Is number > %d? (y/n or yes/no)\n"), middle);
		fgets(response, sizeof(response), stdin);
		if (strcmp(response, _("y\n")) == 0 ||
		    strcmp(response, _("yes\n")) == 0) { left = middle + 1; }
		else if (strcmp(response, _("n\n")) == 0 ||
		         strcmp(response, _("no\n")) == 0) { right = middle; }
	}

	printf(_("The number: %d\n"), left);
	return 0;
}
