#include <stdio.h>
#include <stdlib.h>
#include "ficheros.h"
#include "quebrado.h"

const int NUM_QUEBRADO = 10;

int main()
{
	/*
	//PRUEBAS
	struct quebrado quebrado1  = {1,5};
	struct quebrado quebrado2  = {2,3};
	struct quebrado sumaQuebrado1  = suma(quebrado1,quebrado2);
	struct quebrado quebrado3  = {4,8};
	struct quebrado quebrado4  = {5,2};
	struct quebrado sumaQuebrado2  = suma(quebrado3,quebrado4);


	escribirQuebrado(fichero,&quebrado1);
	escribirQuebrado(fichero,&quebrado2);
	escribirQuebrado(fichero,&sumaQuebrado1);
	escribirQuebrado(fichero,&quebrado3);
	escribirQuebrado(fichero,&quebrado4);
	escribirQuebrado(fichero,&sumaQuebrado2);
	*/
	int i = 0;
	//struct quebrado * mQuebrados = (struct quebrado *)malloc(sizeof(struct quebrado)*10);
	struct quebrado mQuebrados [NUM_QUEBRADO];

	for(i=0;i<9;i++){
		mQuebrados[i].denominador = 0;
		mQuebrados[i].numerador = 0;

	}

	char * fichero = "quebrados";
	

	leerQuebrados(fichero,mQuebrados);
	
	
	for(i=0;i<NUM_QUEBRADO;i++){
		if(mQuebrados[i].denominador!=0)
 			imprimir(mQuebrados[i]);
 	}

    return 0;
}



