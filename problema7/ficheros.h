#ifndef _ficheros_h
#define _ficheros_h
#include <stdio.h>
#include "quebrado.h"



// abre un fichero
FILE * open(char * name);

// cierra fichero
int close(FILE * file);

// lee fichero texto
char * read(char * file);

// tamaño del fichero
int size(FILE * file);

// escribe una estructura quebrado en un fichero
void escribirQuebrado(char * fileName, struct quebrado * q);

void leerQuebrados(char * fileName, struct quebrado mQuebrados[10] );



#endif