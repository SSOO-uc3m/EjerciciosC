/*Ejemplo de uso de librerias para calcular la raiz cuadrada
 * compilar con gcc -lm operaciones.c -o operaciones
 */
//José Manuel Pérez Lobato
#include <stdio.h>
#include <math.h>

main () {
int resto, cociente, numero;
float v=3.6;
numero =20;
resto= numero % 3;
cociente = numero / 3;

printf (" resto = %d, cociente=%d\n", resto, cociente);

numero= v;
printf (" numero = %d, v=%f\n", numero, v);
v= sqrt((double)v);
printf (" numero = %d, v=%f\n", numero, v);
}
