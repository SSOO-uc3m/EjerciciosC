#include <stdio.h>
#include "ficheros.h"

void mostrarMenu();
void leerQuebrado(struct quebrado * q);
void guardarSumaQuebradosf(struct quebrado * p, struct quebrado *q);
void guardarSumaQuebrados(struct quebrado * p, struct quebrado * q);

char * FICHERO = "quebrados";

int main()
{
	struct quebrado quebrado1  = {0};
	struct quebrado quebrado2  = {0};

	char op,kk;


  	do{
 	 	mostrarMenu();
 		scanf ("%c", &op);
 	 	printf ("operacion %c\n",op);
 	 	if (op != '0') {
    		scanf ("%c", &kk); // esta lectura elimina el return de la ultima lectura
    		switch (op){
     		 	case 'i': 
                  leerQuebrado(&quebrado1);
      						leerQuebrado(&quebrado2);
      						guardarSumaQuebrados(&quebrado1,&quebrado2);
                	break;
     			case 's': printf ("fin\n");
                  break;
      			default:  printf ("Opcion erronea\n");
    		}
  		}
	}while (op != 's');

  leerQuebrados(FICHERO);
//system ("pause");


    return 0;
}

void guardarSumaQuebradosf(struct quebrado * p, struct quebrado * q){
  
  struct quebrado sumaQuebrado = suma(*p,*q);  
  escribirQuebradof(FICHERO,p);
  escribirQuebradof(FICHERO,q);
  escribirQuebradof(FICHERO,&sumaQuebrado);
}

void guardarSumaQuebrados(struct quebrado * p, struct quebrado * q){
  
  struct quebrado sumaQuebrado = suma(*p,*q);  
  escribirQuebrado(FICHERO,p);
  escribirQuebrado(FICHERO,q);
  escribirQuebrado(FICHERO,&sumaQuebrado);
}


void leerQuebrado(struct quebrado * q){
	int numerador, denominador;
	char fraccion[10];
	printf("Introduce un quebrado con el formato a/b\n");

	scanf("%s",fraccion);
 	sscanf(fraccion, "%d/%d", &numerador, &denominador);
	q->numerador = numerador;
	q->denominador = denominador;

}

void mostrarMenu(){
  printf ("Suma de quebrados :\n");
  printf ("i introducir quebrados \n");
  printf ("s-fin\n");
}


