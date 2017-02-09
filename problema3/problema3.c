#include <stdio.h>

// Lee un número por teclado y lo devuelve por referencia
void leerint (int *a);

//Recibe dos números enteros y devuelve su suma
int sumar (int a, int b);

//Recibe dos números enteros y devuelve por referencia el cociente y el resto de la división de esos dos números enteros.
void dividir (int a, int b, int *coc, int *resto);

int main()
{
	int num1,num2,suma, cociente, resto;
	
	num1 = num2 = suma = cociente = resto = 0;

	leerint(&num1);
	leerint(&num2);

	suma = sumar(num1,num2);
	printf("la suma de %d + %d es igual a %d\n",num1,num2,suma);
	dividir(num1,num2,&cociente,&resto);
	printf("la división entera de %d / %d tiene cociente %d y resto %d\n",num1,num2,cociente,resto);

    return 0;
}

void leerint (int *a){
	printf("Escribe un número entero\n");
	scanf("%d",a);
}

int sumar (int a, int b){

	return a+b;

}

void dividir (int a, int b, int *coc, int *resto){
	*coc = a/b;
	*resto = a%b;
}

