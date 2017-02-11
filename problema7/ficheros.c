
#include "ficheros.h"
#include "quebrado.h"
#include <stdio.h>
#include <stdlib.h>

const int MAX_QUEBRADO = 10;


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

// escribe fichero texto quebrado
void escribirQuebrado(char * fileName, struct quebrado * q){ 
  //printf("Escribiendo en %s\n", fileName);
  //imprimir(*q);
    FILE * file= fopen(fileName, "ab");
    if (file != NULL) {
      fwrite(q, sizeof(struct quebrado), 1, file);
      fclose(file);
    }
    else{
      perror("Error Escribiendo en fichero ");
    }
}


int numRecords(char * fileName){
  struct quebrado q = {0};
  int numRecords = 0;

  FILE * file= fopen(fileName, "rb");
  if (file != NULL) {

      while (fread(&q,sizeof(struct quebrado),1,file))
      {
         if(!feof(file)){
         numRecords++;
       }
      }
      
      fclose(file);

     }
    else{
      perror("Error Escribiendo en fichero ");
    }
    printf("%d\n", numRecords);
    return numRecords;
}

void leerQuebrados(char * fileName, struct quebrado mQuebrados[MAX_QUEBRADO] ){
  int num = 0, i = 0;
  struct quebrado q = {0};

  FILE *file;
  file=fopen(fileName,"rb");

  if (file != NULL) {

    //printf("Leyendo %s\n", fileName);

     while (fread(&q,sizeof(struct quebrado),1,file))
    {
    
      if(!feof(file) && i<MAX_QUEBRADO){
        
        mQuebrados[i].denominador = q.denominador;
        mQuebrados[i].numerador = q.numerador;
        //imprimir(mQuebrados[i]);

        i++;
      }

    }
    
   
   fclose(file);
  }
  else{
      perror("Error leyendo el fichero ");
    }

}


	
