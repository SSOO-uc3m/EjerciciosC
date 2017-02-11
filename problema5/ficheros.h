#ifndef _quebrado_h
#include <stdio.h>

// abre un fichero
FILE * open(char * name);

// cierra fichero
int close(FILE * file);

// lee fichero texto
char * read(char * file);

// tamaño del fichero
int size(FILE * file);

#endif