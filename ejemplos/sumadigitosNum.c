/* programa que suma los d�gitos de un n�mero */
//Jos� Manuel P�rez Lobato
#include <stdio.h>
main () {
int n,i=0,d,suma=0;
     printf ("Dar n�mero:");
     scanf ("%d",&n);
     while (n>0) {
       d=n%10;
       n=n/10;
       suma=suma+d;
     }
     printf ("suma de d�gitos=%d\n",suma);
}
