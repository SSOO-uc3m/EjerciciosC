/* Calculadora sencilla en varios ficheros*/
//Compilar con gcc principal.c funciones.c 
//José manuel Pérez Lobato
#include <stdio.h>

void pedirNumeros(int *num1, int *n2){
  *num1=33;
  *num1=*num1 + 1; // sumamos 1 al valor entero asociado a num1
  printf ("dar un numero\n");
  scanf ("%d",num1);
  printf ("dar otro numero\n");
  scanf ("%d",n2);
}
int sumar (int num1, int n2){
  int res;
  res=num1+n2;
  return res;
}
void mostrarMenu(){
  printf ("Dar operacion :\n");
  printf ("+ -Sumar \n");
  printf ("- -Restar \n");
  printf ("* -Multiplicar \n");
  printf ("/ -Dividir \n");
  printf ("0-fin\n");
}

