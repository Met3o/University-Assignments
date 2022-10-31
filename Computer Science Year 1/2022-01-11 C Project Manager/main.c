#include <stdio.h>
#include "header.h"
#include <string.h>
//#include "checkdir.c"
//#include "makedir.c"

int main (int argc, char* argv[]){
	char* checkdirString = "checkdir";
	char* makedirString = "makedir";
	char* deletedirString = "deletedir";
	char* deletedirPString = "deletedirP";
//	char* readString = "readFile";
	char* subfoldersearchString = "subfolderSearch";
	char* currentfoldersearchString = "currentfolderSearch";
	char* command = argv[1];
	if ((strcmp(command, checkdirString)) == 0){
		checkdir (argc, argv);
		if (checkdir(argc, argv) == 0){
			printf("%s%s%s\n", "Directory: '", argv[2], "' does not exist (yet!)");
		}
		else{
			printf("%s%s%s\n", "Directory: '", argv[2], "' exists!");
		}
	}
	else if (strcmp(command, makedirString) == 0){
		makedir (argc, argv);
	}
	else if (strcmp(command, deletedirString) == 0){
		deletedir(argc, argv, 0);
	}
	else if (strcmp(command, deletedirPString) == 0){
		deletedirP(argc, argv);
	}
	/*else if (strcmp(command, readString) == 0){
		readFile(argc, argv);
	}*/
	else if (strcmp(command, "readTestfile") == 0){
		readTestfile();
	}
	else if (strcmp(command, subfoldersearchString) == 0 || strcmp(command, "subfoldersearch") == 0){
		subfoldersearch();
	}
	else if (strcmp(command, currentfoldersearchString) == 0 || strcmp(command, "currentfoldersearch") == 0){
		currentfoldersearch();
	}
	else{
		printf ("%s\n", "Invalid input. Please use './pm commandsList' to see the list of commands.");
	}
}
