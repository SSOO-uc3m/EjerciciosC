/*Programa que permite realizar altas, bajas, modificaciones, consultas y 
 * listados sobre los elementos de un array de caracteres de tama�o fijo que
 * se delimita al principio de la ejecuci�n
 */
//Jos� Manuel P�rez Lobato

#include <stdio.h>
#define MAXELEMENTOS 10
#define TRUE 1
#define FALSE 0

int leerArray(int v[]
){
  int num,i;
  printf("Cuantos elementos desea introducir:");
  scanf ("%d",&num);
  for (i=0; i<num; i++){
    printf ("Introduzca elemento de posici�n %d :",i);
    scanf ("%d",&v[i]);
  }
  return num;
}
int menu (){
  int opc;
  do {
     printf ("1-alta\n");
     printf ("2-baja\n");
     printf ("3-modificaci�n\n");
     printf ("4-consulta\n");
     printf ("5-listado\n");
     printf ("0-Salir\n");
     scanf ("%d", &opc);
  } while ((opc <0)|| (opc >5));
  return opc;
}
void alta (int v[], int *nume){
  if (*nume >= MAXELEMENTOS )
    printf ("El array est� LLENO\n");
  else {
    printf ("El elemento ser� dado de alta en la posici�n %d\n", *nume);
    printf ("Introduzca el valor:");
    scanf ("%d", &v[*nume]);
    (*nume)++;
  }
}
int correcta (int pos, int maximo) {
  if ((pos >0) &&(pos <maximo))
    return TRUE;
  else
    return FALSE;
}
void baja (int v[], int *nume){
  int pos,i;
  if (*nume < 0 )
    printf ("El array est� VACIO\n");
  else {
    printf ("Introduzca la posici�n del elemento a dar de baja:");
    scanf ("%d", &pos);
    if (correcta (pos, *nume) ){
      for (i=pos; i< *nume-1; i++)
         v[i]=v[i+1];
      (*nume)--;
    }
    else 
      printf ("ERROR:La posici�n debe estar entre 0 y %d\n", *nume);
  } 
}
void modificacion (int v[], int nume){
  int pos;
  printf ("Introduzca la posici�n del elemento a modificar:");
  scanf ("%d", &pos);
  printf ("Introduzca el nuevo valor del elemento a modificar:");
  scanf ("%d", &v[pos]);
}
void consulta (int v[], int nume){
  int pos;
  printf ("Introduzca la posici�n del elemento a consultar:");
  scanf ("%d", &pos);
  printf ("El valor del elemento de posici�n %d es:%d\n", pos, v[pos]);
}
void listado (int v[], int nume){
  int i;
  for (i=0; i< nume; i++)
    printf ("posici�n %d, valor=%d\n", i, v[i]);
}
main (){
  int v[MAXELEMENTOS],numElementos,opc=1;

  numElementos= leerArray (v);
  while (opc !=0) {
    opc=menu ();
    switch (opc) {
      case 1: alta(v, &numElementos); break;
      case 2: baja(v, &numElementos); break;
      case 3: modificacion(v, numElementos); break;
      case 4: consulta(v, numElementos); break;
      case 5: listado(v, numElementos); break;
    }
  printf ("El array tiene ahora %d elementos\n", numElementos);
  } // fin while
}
