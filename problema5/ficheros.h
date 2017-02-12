#ifndef _quebrado_h
#include <stdio.h>

// abre un fichero
FILE * abrirf(char * fichero);

// cierra fichero
int cerrarf(FILE * descfich);

// lee fichero texto
char * leerf(char * fichero);

// tamaño del fichero
int tamagnof(FILE * descfich);

// Con llamadas al sistema (SYSCALLS)

// abre un fichero 
int abrir(char * fichero);

// cierra fichero 
int cerrar(int descfich);

// lee fichero texto 
char * leer(char * fichero);

// tamaño del fichero
int tamagno(int descfich);


#endif