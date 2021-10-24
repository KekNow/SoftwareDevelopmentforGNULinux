#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc == 1) { printf("help\n"); }
	else {
		int finish, start = 0, inc = 1;
		if (argc >= 3) {
			start = atoi(argv[1]);
			finish = atoi(argv[2]);
			if (argc == 4) { inc = atoi(argv[3]); }
		}
		else { finish = atoi(argv[1]); }
		for (int i = start; i < finish; i += inc) {
			printf("%d\n", i);
		}
	}
	return 0;
}
