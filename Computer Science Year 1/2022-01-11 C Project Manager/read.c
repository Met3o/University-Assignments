#include <stdio.h>
#include "header.h"
int readFile(int argc, char* argv[]){
	FILE *inp = fopen(argv[2], "r");
	char c;
	int check = checkdir(argc, argv);
	if (check == 0){
		printf ("%s\n", "Error, file does not exist.");
	}
	else{
		while(EOF != (c=fgetc(inp))){
			printf("%c",c);
		}
	}
  	fclose(inp);
  	return 0;
}
