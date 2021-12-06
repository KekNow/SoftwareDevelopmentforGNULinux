#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <libintl.h>
#include <string.h>

#include "config.h"
#define LOCALE_PATH "."
#define _(STRING) gettext(STRING)

int main() {
	setlocale (LC_ALL, "");
	bindtextdomain ("binsearch", LOCALE_PATH);
	textdomain ("binsearch");

	printf(_("Choose number from [1..100] (in the mind)\n"));
	char response[3];
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
