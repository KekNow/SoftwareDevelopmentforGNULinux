#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <ctype.h>
#include "config.h"

#define PMATCH 100

int main(int argc, char **argv) {
	if (argc != 4) {
		fprintf(stderr, "Error. Wrong number of input arguments (need ./esub 'input' 'regex' 'sub')\n");
		return 1;
	}

	char *input_str = argv[1];
	char *regex_str = argv[2];
	char *sub_str = argv[3];
	
	regex_t regex;
	regmatch_t pm[PMATCH];
	char buf[128];
	
	int status = regcomp(&regex, regex_str, REG_EXTENDED);
	if (status) {
		regerror(status, &regex, buf, 128);
		fprintf(stderr, "Error. Compilation error. See this: %s\n", buf);
		regfree(&regex);
		return 2;
	}

	status = regexec(&regex, input_str, PMATCH, pm, 0);
	if (status) {
		if (status == REG_NOMATCH) {
			printf("%s\n", input_str);
			return 0;
		}
		else {
			regerror(status, &regex, buf, 128);
			fprintf(stderr, "Error. Mathing error. See this: %s\n", buf);
			regfree(&regex);
			return 3;
		}
	}

	int pocket = 0;
	char *p;
	for (p = sub_str; *p; p++) {
		if (*p == '\\') { pocket = !pocket; }
		else if (pocket) {
			if (!isdigit(*p)) {
				fprintf(stderr, "Error. Error while parsing sub string\n");
				return 4;
			}
			if (pm[*p - '0'].rm_so < 0) {
				fprintf(stderr, "Error. Error while parsing sub string\n");
				return 5;
			}
			pocket = 0;
		}
	}
	if (pocket) {
		fprintf(stderr, "Error. Error while parsing sub string\n");
		return 6;
	}

	printf("%.*s", pm[0].rm_so, input_str);
	for (p = sub_str; *p; p++) {
		if (*p == '\\') {
			if (pocket) { putchar(*p); }
			pocket = !pocket;
		}
		else if (pocket) {
			int start = (int) pm[*p - '0'].rm_so;
			int finish = (int) pm[*p - '0'].rm_eo;
			printf("%.*s", finish - start, input_str + start);
			pocket = 0;
		}
		else { putchar(*p); }
	}
	printf("%s\n", input_str + pm[0].rm_eo);

	return 0;
}
