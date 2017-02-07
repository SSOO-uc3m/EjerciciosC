/* programa que suma los dígitos de un número */
//José Manuel Pérez Lobato
#include <stdio.h>
main () {
int n,i=0,d,suma=0;
     printf ("Dar número:");
     scanf ("%d",&n);
     while (n>0) {
       d=n%10;
       n=n/10;
       suma=suma+d;
     }
     printf ("suma de dígitos=%d\n",suma);
}
