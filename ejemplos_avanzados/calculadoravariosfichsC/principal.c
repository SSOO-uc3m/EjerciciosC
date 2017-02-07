/*Calculadora sencilla en varios ficheros*/
//Compilar con gcc principal.c funciones1.c
//José Manuel Pérez Lobato
#include <stdio.h>
#include "datos.h"

main (){
int n1,n2, res;
char op,kk;

pedirNumeros(&n1, &n2);
do{
  mostrarMenu();
  scanf ("%c", &kk); // esta lectura elimina el return de la ultima lectura
  scanf ("%c", &op);
  printf ("operacion %c\n",op);
  switch (op){
    case '+': res=sumar(n1,n2);break;
    case '-': res=n1-n2;break;
    case '*': res=n1*n2;break;
    case '/': res=n1/n2;break;
    case '0': printf ("fin\n"); break;
    default: printf ("Opcion erronea\n");
  }
  printf ("Resultado =%d\n", res);
}while (op != '0');
}


