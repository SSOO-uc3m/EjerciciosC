
#include "quebrado.h"
#include <stdio.h>

struct quebrado suma (struct quebrado q, struct quebrado p){
	struct quebrado sumaQuebrado = {0};

	sumaQuebrado.numerador = p.numerador*q.denominador + q.numerador*p.denominador;
	sumaQuebrado.denominador = p.denominador*q.denominador;

	return sumaQuebrado;
}

struct quebrado resta (struct quebrado q, struct quebrado p){
	struct quebrado restaQuebrado = {0};
	restaQuebrado.numerador =  q.numerador*p.denominador - p.numerador*q.denominador ;
	restaQuebrado.denominador = p.denominador*q.denominador;

	return restaQuebrado;
}

struct quebrado multiplicacion (struct quebrado q, struct quebrado p){
	struct quebrado productoQuebrado = {0};

	productoQuebrado.numerador=p.numerador*q.numerador;
 	productoQuebrado.denominador=p.denominador*q.denominador;

	return productoQuebrado;
}

struct quebrado division (struct quebrado q, struct quebrado p){
	struct quebrado divisionQuebrado = {0};

	divisionQuebrado.numerador  =q.numerador*p.denominador;
	divisionQuebrado.denominador =q.denominador*p.numerador;

	return divisionQuebrado;
}

void reducir (struct quebrado * q){
    int MCD = mcd(q->numerador, q->denominador);

    q->numerador= q->numerador/MCD;
    q->denominador =q->denominador/MCD;

}



void  imprimir (struct quebrado q){
	
    reducir(&q);

	printf("%d/%d \n",q.numerador,q.denominador);

}

// función que calcula el máximo común divisor
int mcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

