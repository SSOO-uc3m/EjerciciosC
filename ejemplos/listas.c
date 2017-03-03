Skip to content
This repository
Search
Pull requests
Issues
Gist
 @carlostessier
 Sign out
 Unwatch 1
  Star 0
 Fork 0 ProgramacionC/TAD
 Code  Issues 0  Pull requests 0  Projects 0  Wiki  Pulse  Graphs  Settings
Branch: master Find file Copy pathTAD/Listas/main.c
f2c3531  on 12 Nov 2015
@carlostessier carlostessier commiti inicial
1 contributor
RawBlameHistory     
242 lines (188 sloc)  4.09 KB

#include <stdlib.h>
#include <stdio.h>

#define MX 9

typedef enum {FALSE = 0, TRUE = 1} BOOLEAN;
typedef BOOLEAN Boolean;

typedef int Item;
typedef struct Nodo
{
	Item info;
	struct Nodo* sig;
	
} NODO;
typedef NODO Nodo;

void EliminarPosicion(Nodo **Lista, int posicion);
int esVacia (Nodo *Lista);
void CrearLista (Nodo **Lista);
void DestruirLista (Nodo **Lista);
void InsertarPrimeroLista(Nodo ** Primero, Item dato);
void ImprimeLista(Nodo *Lista);
Nodo* BuscarLista (Nodo* Lista, Item dato);



/*
 * 18.1 Escriba una funci—n que devuelva cierto si la lista est‡ vac’a y falso en otro caso,
 * y otra que cree una lista vac’a
 */

int esVacia (Nodo *Lista)
{
	return (Lista == NULL);
}

void CrearLista (Nodo **Lista)
{
	*Lista = NULL;
}

void IraSiguiente (Nodo **Lista)
{
	Nodo *ptr = *Lista;
	
	if (!esVacia(ptr)) *Lista = ptr->sig;
}

void DestruirLista (Nodo **Lista)
{
	Nodo *temp;
	Nodo *ptr = *Lista;
		
	while(ptr!=NULL)
	{
		temp = ptr;
		IraSiguiente(&ptr);
		free(temp);
	} 
	
	*Lista = NULL;
		
}
/*
   18.2 Escriba una funci—n entera que devuelva el nœmero de nodos de una lista enlazada
 */

int NumNodos(Nodo *Lista)
{
	Nodo *temp = Lista;
	int i=0;
	if (!esVacia(Lista))
	{
		while(temp!=NULL)
		{
			IraSiguiente(&temp);
			i++;
		}
	}
	//else printf("No hay ningun nodo\n");
	
	return i;
}

/*
 * 18.3 Escriba una funci—n que elimine el nodo que ocupa la posici—n i de una lista enlazada ordenada
 */

void EliminarPosicion(Nodo **Lista, int posicion)
{
	Nodo *ptr = *Lista;
	Nodo *ant = NULL;
	int i=1;
	
	if (!esVacia(ptr)&&(posicion>0))
	{
		while ((ptr->sig!=NULL)&&(i<posicion)) 
		{
			i++;
			ant = ptr;
			IraSiguiente(&ant);	
		}
		if (i == posicion) 
		{
			// À?
			if (ant == NULL) *Lista = ptr->sig;
			else 
			{
				ant->sig = ptr->sig;
				free(ptr);
			}
		}
		else printf("La posicion %d no ha sido encontrada\n",posicion);
		
	}
}

/*
 18.4 Escriba una funci—n que reciba como par‡metro una lista enlazada apuntada por el Primero (circular), un dato 
 cualquiera e inserte en la lista enlazada un nuevo nodo con la informaci—n almacenada en dato y de tal forma que sea 
 el primer elemento de la lista
*/

void InsertarPrimeroLista(Nodo ** Primero, Item dato){

	//printf("Inserta primero en lista\n");
	Nodo *nuevo;
	nuevo = (Nodo*)malloc(sizeof(Nodo));
	nuevo -> info = dato;
	nuevo -> sig = *Primero;
	*Primero = nuevo;
}

/*
 18.5 Escriba una funci—n que reciba como par‡metro un puntero ant que apunte a un nodo de una lista enlazada e inserte el
 valor recibido en el par‡metro dato como un nuevo nodo que estŽ inmediatamente despuŽs de ant (Inserci—n en el centro y
 final de una lista);
 */


void InsertarLista(Nodo **Lista, Item dato){
	
	Nodo *ptr = *Lista;
	Nodo *ant = NULL;
	Nodo *nuevo;
	
	nuevo = (Nodo*)malloc(sizeof(Nodo));
	
	if(esVacia(ptr)) 
	{
		InsertarPrimeroLista(Lista, dato);
	}
	else 
	{
		while ((ptr!=NULL)&&(ptr->info<dato)) {
			ant = ptr;
			IraSiguiente(&ptr);
		}
		if (ant==NULL) // En caso de ser el primero
		{
			*Lista = nuevo;
			nuevo->sig = ptr;
			nuevo-> info = dato;
		}
		else 
		{
			ant->sig = nuevo;
			nuevo->sig = ptr;
			nuevo-> info = dato;
		}
	}
	
}	

void ImprimeLista(Nodo *Lista)
{
	Nodo *temp = Lista;
	
	if (esVacia(Lista))
	{ printf("No puedo imprimir, lista vacia\n");}
	else
	{
		while(temp!=NULL)
		{
			printf(" %d ->",temp->info);
			temp = temp->sig;
		}
	}
	printf("\n");
}
	
/* 
 Escriba una funci—n que reciba como datos un puntero nodo de una lista enlazada y un dato a buscar
 y devuelva NULL si el dato no est‡ en la lista y un puntero a la primera aparici—n del dato en otro caso. 
*/

Nodo* BuscarLista (Nodo* Lista, Item dato)
{
	Nodo *temp;
	
	for (temp = Lista; temp!=NULL; temp = temp->sig) 
	{
		if (temp->info == dato)
		{
			return temp;
		}
	
	}
	
	return NULL;
	
}

int main(int argc, char* argv[]) {
	
	Nodo *lista;
	int k;
	
	CrearLista(&lista);
	
	//InsertarPrimeroLista(&lista, rand()%MX);
	
	
	
	for (k=0; k<MX; k++) {
		//printf("%d\n",rand()%MX);
		InsertarPrimeroLista(&lista, rand()%MX);
	}
	
	ImprimeLista(lista);
	
	DestruirLista(&lista);
	
	//EliminarPosicon(&lista, 2);

	ImprimeLista(lista);
	
	printf("num nodos %d",NumNodos(lista));
	
}
