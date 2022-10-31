#ifndef __HEADER_H_
#define __HEADER_H_

int checkdir (int, char*[]);
int makedir (int, char*[]);
int deletedir (int, char*[], char*);
int deletedirP(int, char*[]);
int readTestfile(void);
//int readFile (int, char*[]);
int subfoldersearch(void);
int currentfoldersearch(void);
#endif
