
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <stdio.h>
#include <stdlib.h>
#include "ficheros.h"

// abre fichero con syscalls
int abrir(char * name){
	int descfich;
	descfich = open(name, O_RDONLY);
	return descfich;
} 

// cierra fichero con syscalls
int cerrar(int descfich){
  if(close(descfich) < 0)
        return 1;
 
    return 0;
}

// lee fichero texto con syscalls
char * leer(char * file){
  char * buffer = 0;
  int descfich = 0, length = 0;

  descfich = abrir(file);
  if (descfich){
    printf("leyendo fichero\n");
    length = tamagno(descfich);
    printf("tamaño %d\n", length);
    buffer = malloc (length);
    if (buffer)
      {
        read (descfich, buffer, length);
      }   
   
    cerrar (descfich);
  }
  else {
      fprintf (stderr, "No se ha podido abrir el fichero\n");
  }
    return buffer;

}

// tamagno del fichero con llamadas al sistema
int tamagno(int descfich){

    struct stat fileStat;

    if(fstat(descfich,&fileStat) < 0)    
        return 1;
    return fileStat.st_size;

}

// abre fichero
FILE * abrirf(char * name){
  FILE *fp;
  fp = fopen(name, "r");
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



	
