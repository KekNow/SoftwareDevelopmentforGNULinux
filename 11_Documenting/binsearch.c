/*! 
 * \Binsearch using human
 *
 * Usage: ./binsearch [OPTIONS]\n
 *   \-\-version   print current version \n
 *   \-\-help      print help \n
 *   \-r           use roman numerals \n
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <libintl.h>
#include <string.h>

#include "config.h"
#define LOCALE_PATH "."
#define _(STRING) gettext(STRING)

#define MANUAL _("Binsearch using human\n\
\n\
Usage: ./binsearch [OPTIONS] \n\
\n\
    --version   print current version \n\
    --help      print help \n\
    -r          use roman numerals \n")

char* roman_numerals[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX", "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL", "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L", "LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX", "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX", "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX", "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC", "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"};

/**
* Describe
* @param i The number from 1 to 100
* 
* @returns 
*/
char* romanize(int num) {
	return roman_numerals[num - 1];
}

/**
* Describe
* @param rome_num The number from I to C in roman numeral system
* 
* @returns The number decimal system
*/
int unromanize(char* rome_num) {
	for (int i = 0; i < sizeof(roman_numerals); i++) {
		if (strcmp(rome_num, roman_numerals[i]) == 0) { return i + 1; }
	}
}

/**
 * @param
 */
int main(int argc, char** argv) {
	setlocale (LC_ALL, "");
	bindtextdomain ("binsearch", LOCALE_PATH);
	textdomain ("binsearch");
	
	int roman = 0;
	if (argc == 2) {
		if (strcmp(argv[1], "-r") == 0) {
			roman = 1;
		}
		else if (strcmp(argv[1], "--help") == 0) {
			return printf(MANUAL);
		}
		else if (strcmp(argv[1], "--version") == 0) {
			return printf("%s\n", VERSION);
		}
	}

	printf(_("Choose number from [1..100] (in the mind)\n"));
	char response[10], str[10];
	int left = 1, right = 100, middle;
	while (left < right) {
		middle = (left + right) / 2;
		sprintf(str, "%d", middle);
		printf(_("Is number > %s? (y/n or yes/no)\n"), roman ? romanize(middle) : str);
		fgets(response, sizeof(response), stdin);
		if (strcmp(response, _("y\n")) == 0 ||
		    strcmp(response, _("yes\n")) == 0) { left = middle + 1; }
		else if (strcmp(response, _("n\n")) == 0 ||
		         strcmp(response, _("no\n")) == 0) { right = middle; }
	}
	sprintf(str, "%d", left);
	printf(_("The number: %s\n"), roman ? romanize(left) : str);

	return 0;
}
