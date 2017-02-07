/*Ejemplo para ver la diferencia entre sizeof y strlen
 */
//Jos� Manuel P�rez Lobato
#include <stdio.h>
#include <string.h>

tamanos(int *v, char cad[]){
  printf ("Funcion:tamano de v:%d\n",sizeof(v));
  strcpy (cad,"Hola Ana");
  printf ("Funcion:tamano de cad:%d\n",sizeof(cad));
  printf ("Funcion:longitud de cad:%d\n",strlen(cad));
}
main (){
int v[10];
char cad[12];

printf ("MAIN:tamano de v:%d, n�mero de posiciones del array=%d\n",sizeof(v), sizeof(v)/sizeof(int));
strcpy (cad,"Hola Ana");
printf ("MAIN:tamano de cad:%d, n�mero de posiciones del array=%d\n",sizeof(cad),sizeof(cad)/sizeof(char));
printf ("MAIN:longitud de cad:%d\n",strlen(cad));

tamanos(v,cad);
}
/*Resultado de la ejecuci�n:
MAIN:tamano de v:40, n�mero de posiciones del array=10
MAIN:tamano de cad:12, n�mero de posiciones del array=12
MAIN:longitud de cad:8
Funcion:tamano de v:4
Funcion:tamano de cad:4
Funcion:longitud de cad:8
*/
