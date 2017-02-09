#include <stdio.h>
#include "quebrado.h"

void leerQuebrado(struct quebrado * q){
	int numerador, denominador;
	scanf ("%d" ,&numerador);
	scanf ("%d" ,&denominador);
	q->numerador = numerador;
	q->denominador = denominador;

}

int compararQuebrado(struct quebrado q1, struct quebrado q2){
	return (q1.denominador == q2.denominador) && (q1.numerador=q2.numerador);

}

void casoDePrueba () {
	struct quebrado quebrado1  = {0};
	struct quebrado quebrado2  = {0};
	struct quebrado sumaQuebrado = {0};
	leerQuebrado(&quebrado1);
	leerQuebrado(&quebrado2);
	leerQuebrado(&sumaQuebrado);

	//suma
	
	if (compararQuebrado(sumaQuebrado,suma(quebrado1,quebrado2)) < 1){
		printf("Error suma\n");
		imprimir(quebrado1);
		imprimir(quebrado2);
		imprimir(sumaQuebrado);
		imprimir(suma(quebrado1,quebrado2));

	}

}
	



int main()
{
	/*
	struct quebrado quebrado1  = {3,8};
	struct quebrado quebrado2  = {1,2};
	struct quebrado quebradoResult = {0};

	printf("quebrado 1: ");
	imprimir(quebrado1);

	printf("quebrado 2: ");
	imprimir(quebrado2);

	quebradoResult = suma(quebrado1,quebrado2);
	printf("suma: "); 
	imprimir(quebradoResult);

	quebradoResult = resta(quebrado1,quebrado2);
	printf("resta: "); 
	imprimir(quebradoResult);

	quebradoResult = multiplicacion(quebrado1,quebrado2);
	printf("mul: "); 
	imprimir(quebradoResult);

	quebradoResult = division(quebrado1,quebrado2);
	printf("div: "); 
	imprimir(quebradoResult);*/

	int numCasos ;
	int i ;
	scanf ("%d\n " , &numCasos ) ;
	for(i=0;i<1;i++)
		casoDePrueba();


    return 0;
}
