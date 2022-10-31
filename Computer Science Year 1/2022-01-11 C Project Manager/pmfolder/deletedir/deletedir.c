#include <stdio.h>
#include <ftw.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include "../../header.h"

int deletedir(int argc, char* argv[], char* name){
	name = argv[2];
	DIR *directory = opendir(name);
	size_t nameLength = strlen (name);
	int i = -1;

	if (directory){
		struct dirent *path;
		i = 0;
		while (!i && (path = readdir(directory))){
			int i2 = -1;
			char *buffer;
			size_t length;

			if (!strcmp(path->d_name, ".") || !strcmp (path->d_name, "..")){
				continue;
			}
			length = nameLength + strlen(path->d_name) + 2;
			buffer = malloc (length);

			if (buffer) {
				struct stat statBuffer;

				snprintf (buffer, length, "%s/%s", name, path->d_name);
				if (!stat(buffer, &statBuffer)){
					if (S_ISDIR(statBuffer.st_mode)){
						i2 = deletedir(argc, argv, buffer);
					}
					else{
						i2 = unlink(buffer);
					}
				}
				free(buffer);
			}
			i = i2;
		}
		closedir(directory);
	}
	if (!i){
		i = rmdir(name);
	}
	return i;
}
