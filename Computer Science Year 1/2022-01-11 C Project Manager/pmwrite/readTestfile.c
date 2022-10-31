#include <stdio.h>
#include "../header.h"

#define BUFSIZE 200
int readTestfile(void){
  FILE *inp=fopen("./testfile","r");
  char c[BUFSIZE];
  // int x=0;
  while(fscanf(inp, "%[^\n]\n",c) != EOF){
    printf("%s\n",c);
  }
  fclose(inp);
  return 0;
}
