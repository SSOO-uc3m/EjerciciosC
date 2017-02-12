#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <stdio.h>
#include <stdlib.h>
#include "ficheros.h"
#include "quebrado.h"

// abre fichero con syscalls
int abrir(char * name){
  int descfich;
  descfich = open(name, O_RDONLY);
  return descfich;
} 

// abre fichero para escritura con append, si no existe lo crea
int agnadir(char * name){
  int descfich;
  descfich = open(name, O_WRONLY|O_APPEND| O_CREAT | S_IRWXU);

  return descfich;
} 

// cierra fichero con syscalls
int cerrar(int descfich){
  if(close(descfich) < 0)
        return 1;
 
    return 0;
}

void leerQuebrados(char * fileName ){
  int descfich;
  struct quebrado q = {0};

  descfich=abrir(fileName);

  if (descfich) {

     while (read(descfich,&q,sizeof(struct quebrado))) { 
      imprimir(q);
        
      } 
   
   cerrar(descfich);
  }
  else{
      fprintf (stderr, "No se ha podido leer el fichero\n");
    }

}

// abre fichero
FILE * abrirf(char * name){
	FILE *fp;
	fp = fopen(name, "rb");
	return fp;
} 

// abre fichero
FILE * agnadirf(char * name){
  FILE *fp;
  fp = fopen(name, "ab");
  return fp;
} 


// cierra fichero
int cerrarf(FILE * file){
	if(file == NULL) 
   {
      perror("Error closing file");
      return(-1);
   }
   fclose(file);
   return 0;
}

// lee fichero texto
char * leerf(char * file){
	char * buffer = 0;
	FILE *fp;
	int length = 0;

	fp = abrirf(file);
	if (fp){
		length = tamagnof(fp);
		buffer = malloc (length);
 
  		if (buffer)
  		{
    		fread (buffer, 1, length, fp);
  		}
  	cerrarf (fp);
  }
  else {
      perror("Error reading file");
  }
  	return buffer;

}

// tamaño del fichero
int tamagnof(FILE * file){
	int size = 0;

	if(file == NULL) 
   {
      perror("Error closing file");
      return(-1);
   }

	fseek(file, 0, SEEK_END); 
	size = ftell(file); 
	//volvemos al inicio
	fseek(file, 0, SEEK_SET);

	return size;
}

// escribe al final del fichero texto quebrado
void escribirQuebradof(char * fileName, struct quebrado * q){ 
  printf("Escribiendo en %s\n", fileName);
  imprimir(*q);
    FILE * file= agnadirf(fileName);
    if (file != NULL) {
      fwrite(q, sizeof(struct quebrado), 1, file);
      cerrarf(file);
    }
    else{
      perror("Error Escribiendo en fichero ");
    }
}

// escribe al final del fichero texto quebrado
void escribirQuebrado(char * fileName, struct quebrado * q){ 
  
    int descfich= agnadir(fileName);
    if (descfich) {
        printf("Escribiendo en %s\n", fileName);
        imprimir(*q);
        write(descfich, q,sizeof(struct quebrado));
        cerrar(descfich);
    }
    else{
      fprintf (stderr, "No se ha podido escribir en el fichero\n");
    }
}

void leerQuebradosf(char * fileName ){
  
  struct quebrado q = {0};

  FILE *file;
  file=abrirf(fileName);

  if (file != NULL) {

    //printf("Leyendo %s\n", fileName);

     while (fread(&q,sizeof(struct quebrado),1,file))
    {
    
      if(!feof(file)){
        
          imprimir(q);
        
      }

    }    
   
   cerrarf(file);
  }
  else{
      perror("Error leyendo el fichero ");
    }

}


	
