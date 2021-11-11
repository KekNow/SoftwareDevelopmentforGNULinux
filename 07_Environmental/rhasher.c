#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <rhash.h>
#include "config.h"

//#define READLINE_FLAG 1
#if READLINE_FLAG
	#include <readline/readline.h>
	#include <readline/history.h>
#endif

ssize_t readline_or_getline(char **line) {
	#if READLINE_FLAG
		*line = readline(NULL);
		return strlen(*line);
	#else
		size_t length = 0;
		return getline(line, &length, stdin);
	#endif
}
 
int main() {
	rhash_library_init();
	
	int result, base_or_hex = 0, hash_type = 0;
	char *in_hash, *in_str, *line = NULL;
	char output[128], digest[128];

	while (readline_or_getline(&line) >= 0) {
		in_hash = strtok(line, " ");
		in_str = strtok(strtok(NULL, " "), "\n");
		
		if (!in_hash || !in_str) {
			fprintf(stderr, "Error. Input string is empty\n");
			continue;
		}
		
		if (isupper(in_hash[0])) { base_or_hex = RHPR_HEX; }
		else { base_or_hex = RHPR_BASE64; }

		in_hash[0] = tolower(in_hash[0]);
		if (strcmp(in_hash, "md5") == 0) {
			hash_type = RHASH_MD5;
		}
		else if (strcmp(in_hash, "sha1") == 0) {
			hash_type = RHASH_SHA1;
		}
		else if (strcmp(in_hash, "tth") == 0) {
			hash_type = RHASH_TTH;
		}
		else {
			fprintf(stderr, "Error. Please try md5, sha1, tth\n");
			continue;
		}
		
		if (in_str[0] == '"') { result = rhash_msg(hash_type, in_str + 1, strlen(in_str) - 1, digest); }
		else { result = rhash_file(hash_type, in_str, digest); }
		
		if (result < 0) {
			fprintf(stderr, "Error. Hash computation error\n");
			continue;
		}
		rhash_print_bytes(output, digest, rhash_get_digest_size(hash_type), base_or_hex);
		printf("%s\n", output);
    }
    
    if (line) { free(line); }
    return 0;
}
