#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	if (argc != 3) {
		fprintf(stderr, "wrong number of input arguments\n");
		return 1;
	}
	if (strcmp(argv[1], argv[2]) == 0) {
		fprintf(stderr, "infile and outfile should be different\n");
		return 2;
	}

	FILE *infile, *outfile;

	infile = fopen(argv[1], "r");
	if (infile == NULL) {
		fprintf(stderr, "error while opening infile\n");
		return 3;
	}
	outfile = fopen(argv[2], "wb");
	if (outfile == NULL) {
		fprintf(stderr, "error while opening outfile\n");
		return 4;
	}
	
	int size_buf;
	char buf[100];
	while (feof(infile) == 0) {
		if ((size_buf = fread(buf, sizeof(char), 100, infile)) != 100 && !feof(infile)) {
			fprintf(stderr, "error while reading the buf[100]\n");
			fclose(infile);
			fclose(outfile);
			remove(argv[2]);
			return 5;
		}
		if (fwrite(buf, sizeof(char), size_buf, outfile) < size_buf) {
			fprintf(stderr, "error while writing the buf[100]\n");
			fclose(infile);
			fclose(outfile);
			remove(argv[2]);
			return 6;
		}
	}

	if (fclose(infile) != 0) {
		fprintf(stderr, "error while closing infile\n");
		fclose(outfile);
		remove(argv[2]);
		return 7;
	}
	if (fclose(outfile) != 0) {
		fprintf(stderr, "error while closing outfile\n");
		remove(argv[2]);
		return 8;
	}
	if (remove(argv[1]) != 0) {
		fprintf(stderr, "error while deleting infile\n");
		remove(argv[2]);
		return 9;
	}
	return 0;
}
