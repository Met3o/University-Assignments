#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../../header.h"

int checkdir(int argc, char* argv[]){
	char* name = argv[2];
	// If more than 2 arguments (command name + arg name) then count all and return an error.
	if (argc > 3){
		printf ("%s\n", "Will only check the first requested word.");
	}
	DIR* dir = opendir(name);
	if (dir) {
		// Directory exists.
//		printf ("%s%s%s%s%s\n", "Requested: ", name, ".\n", name, " exists!\n");
		// "Directoryname exists!"
		closedir(dir);
		return 1;
	}
	else if (ENOENT == errno) {
		// Directory does not exist.
		return 0;
//		printf ("%s%s%s%s%s\n", "Requested: ", name, ".\n", name, " does not exist!\n");
	}
	else {
		// Other failure.
		printf ("%s\n", "Our sources have encountered an error. Please try again. Sorry.");
		return -1;
	}
}


