#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include "../../header.h"
#include <limits.h>

int makedir (int argc, char* argv[]){
	int checkIfExists = checkdir(argc, argv);
	printf("%d\n", checkIfExists);
	if (checkIfExists == 1){
		printf ("%s\n", "Exists");
	}
	else{
		char *directory = argv[2];
		char temp[PATH_MAX];
		char *parents = NULL;
		size_t length;
		snprintf(temp, sizeof(temp), "%s", directory);
		length = strlen(temp);
		if (temp[length - 1] == '/'){
			temp[length - 1] = 0;
		}
		for (parents = temp + 1; *parents; parents++){
			if (*parents == '/') {
				*parents = 0;
				mkdir(temp, S_IRWXU);
				*parents = '/';
			}
		}
		mkdir (temp, S_IRWXU);
		printf("%s%s\n", "Successfully created directory: ", directory);
		}
	return 0;
}
