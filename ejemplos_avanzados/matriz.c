/*
 * Programa que lee una matriz y despu�s la muestra por pantalla
 */
//Jos� Manuel P�rez Lobato
#include <stdio.h>
#define NUMFILAS 4
#define NUMCOLUMNAS 4

void leerMatriz(int m[][NUMCOLUMNAS]);
void escribirMatriz(int m[NUMFILAS][NUMCOLUMNAS]);
main () {
 int m[NUMFILAS][NUMCOLUMNAS];

 leerMatriz(m);
 escribirMatriz(m);
}

void leerMatriz(int m[][NUMCOLUMNAS]){
 int i,j;
 for (i=0; i<NUMFILAS; i++)
   for (j=0; j<NUMCOLUMNAS; j++){
     printf ("Dar elemento m[%d][%d] : \n",i,j);
     scanf ("%d",&m[i][j]);
printf ("Elemento m[%d][%d] vale: \n",i,j,m[i][j]);
   }
}
void escribirMatriz(int m[NUMFILAS][NUMCOLUMNAS]){
 int i,j;
 for (i=0; i<NUMFILAS; i++)
   for (j=0; j<NUMCOLUMNAS; j++)
     printf ("Elemento m[%d][%d] vale: %d\n",i,j,m[i][j]);
}



