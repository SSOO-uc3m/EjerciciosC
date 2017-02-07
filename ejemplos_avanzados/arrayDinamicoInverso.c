#include <stdio.h>
#include <stdlib.h>
#define MAXELEMENTOS 10
#define TRUE 1
#define FALSE 0

/*Ejemplo de utilizaci�n de arrays din�micos*/
/*programa que pide n�meros al usuario, tantos como desee el usuario y despu�s 
los muestra en orden inverso al de lectura */
/*Autor Jos� Manuel P�rez Lobato */

int *leerArray( int *numE); /*devuelve el array asociado al nombre de la funcisn, y el numero de elementos como parametro.
Si quisiera devolver el array como parametro deberma tener algo como
void leerArray (int *numE, int **v);
*/

void listadoInverso (int *v, int nume);

main () {
  int numElementos;
  int *v;
  
  v= leerArray(&numElementos);
  listadoInverso(v, numElementos);
}
  

int *leerArray( int *numE){
  int i, *v;
  printf("Cuantos elementos desea introducir:");
  scanf ("%d",numE);
  v=(int *) malloc (*numE * sizeof(int) );
  for (i=0; i<*numE; i++){
    printf ("Introduzca elemento de posici�n %d : ",i);
    /*  Esta es la forma alternativa de leer : scanf ("%d",(v+i)); */
    scanf ("%d",&v[i]);
  }
  return v;
}
void listadoInverso (int *v, int nume){
  int i;
  for (i=nume-1; i>= 0; i--)
    /* esta es la forma alternativa de escribir :
       printf ("posici�n %d, valor=%d\n", i, *(v+i)); */
    printf ("posici�n %d, valor=%d\n", i, v[i]);
}
