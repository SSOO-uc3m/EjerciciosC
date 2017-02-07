/*Ejemplo de uso del printf*/
//José Manuel Pérez Lobato
#include <stdio.h>
main () {
	long int num1,num=9;
	double r=5.1; 
	printf (":%d: :%4d: :%-4d: :%6.4d: :%2d:\n", num, num, num, num, 111);
	printf (":%f: :%9f: :%-9f: :%9.4f: :%2f: \n", r, r, r, r, 111);
	printf (":%c: :%s: :%7s: :%-7s: :%7.4s:\n", 'a', "uno", "dos", "tres", "cuatro");

	printf ("dar numeros separados por :\n");
	scanf ("%d:%d", &num, &num1);
	printf (":%d::%d:\n", num, num1);
	
	printf ("dar numeros separados por :\n");
	scanf ("%d:%d", &num, &num1);
	printf (":%d::%d:\n", num, num1);
}
