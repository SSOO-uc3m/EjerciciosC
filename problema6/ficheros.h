#ifndef _ficheros_h
#define _ficheros_h
#include <stdio.h>
#include "quebrado.h"

// abre un fichero
FILE * abrirf(char * fichero);

FILE * agnadirf(char * name);

// cierra fichero
int cerrarf(FILE * descfich);

// lee fichero texto
char * leerf(char * fichero);

// tamaño del fichero
int tamagnof(FILE * descfich);

// escribe una estructura quebrado en un fichero
void escribirQuebradof(char * fileName, struct quebrado * q);

void leerQuebradosf(char * fileName );

// Con llamadas al sistema (SYSCALLS)

// abre un fichero 
int abrir(char * fichero);

int agnadir(char * name);

// cierra fichero 
int cerrar(int descfich);

// lee fichero texto 
char * leer(char * fichero);

// tamaño del fichero
int tamagno(int descfich);

// escribe una estructura quebrado en un fichero
void escribirQuebrado(char * fileName, struct quebrado * q);

void leerQuebrados(char * fileName );


#endif