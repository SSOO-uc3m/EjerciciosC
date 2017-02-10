
#include "ficheros.h"
#include <stdio.h>
#include <stdlib.h>

// abre fichero
FILE * open(char * name){
	FILE *fp;
	fp = fopen(name, "r");
	return fp;
} 

// cierra fichero
int close(FILE * file){
	if(file == NULL) 
   {
      perror("Error closing file");
      return(-1);
   }
   fclose(file);
   return 0;
}

// lee fichero texto
char * read(char * file){
	char * buffer = 0;
	FILE *fp;
	int length = 0;
	printf("reading %s",file);

	fp = fopen(file, "r");
	if (fp){
		length = size(fp);
		buffer = malloc (length);
 
  		if (buffer)
  		{
    		fread (buffer, 1, length, fp);
  		}
  	fclose (fp);
  }
  else {
      perror("Error reading file");
  }
  	return buffer;

}

// tamaño del fichero
int size(FILE * file){
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

	
