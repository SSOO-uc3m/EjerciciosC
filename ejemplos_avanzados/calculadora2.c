/* Ejercicio:
             Realizar una calculadora sencilla que permita realizar sumas, restas, multiplicaciones 
             y divisiones de números enteros.
             Se deberán implementar, al menos, las siguientes funciones:
             Función para leer los datos del teclado. 
             Función que sume 2 números (deBerá devolver el valor por medio del return)
             Función que reciba 2 números y devuelva el cociente y el resto de la división entera.
/*Calculadora sencilla */
//José Manuel Pérez Lobato
#include <stdio.h>

void pedirNumeros(int *num1, int *n2);
int sumar (int num1, int n2);
int dividir (int n1, int n2, int *coc, int *resto);
void mostrarMenu();

main (){
int n1,n2, coc, res;
char op,kk;

do{
  mostrarMenu();
  scanf ("%c", &op);
  printf ("operacion %c\n",op);
  if (op != '0') {
    pedirNumeros(&n1, &n2);
    scanf ("%c", &kk); // esta lectura elimina el return de la ultima lectura
    switch (op){
      case '+': res=sumar(n1,n2);
                printf ("Resultado =%d\n", res);
                break;
      case '-': res=n1-n2;
                printf ("Resultado =%d\n", res);
                break;
      case '*': res=n1*n2;
                printf ("Resultado =%d\n", res);
                break;
      case '/': dividir(n1,n2, &coc,&res);
                printf ("Cocciente= %d, Resto=%d\n", coc, res);
                break;
      case '0': printf ("fin\n"); break;
      default:  printf ("Opcion erronea\n");
    }
  }
}while (op != '0');
//system ("pause");
}

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
int dividir (int n1, int n2, int *coc, int *resto){
      *coc=n1/n2;
      *resto=n1%n2;
}
void mostrarMenu(){
  printf ("Dar operacion :\n");
  printf ("+ -Sumar \n");
  printf ("- -Restar \n");
  printf ("* -Multiplicar \n");
  printf ("/ -Dividir \n");
  printf ("0-fin\n");
}

