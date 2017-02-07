/*Ejemplo de porque hay que poner \n al final de la escritura.
 * La cadena Hola tarda 4 seg en aparecer
 */
//José Manuel Pérez Lobato
#include <stdio.h>

main(){
  printf ("\nHola");
  sleep (4);
  printf ("adios");
}
