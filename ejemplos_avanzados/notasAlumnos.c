/* Este programa pide las notas de varios alumnos al usuario (3 notas por 
 * alumno) y después calcula la media */
//José Manuel Pérez Lobato

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMALUMNOS 5
#define NUMNOTAS 3

struct Alumno {
  char nombre[20];
  int NIA;
  float notas[NUMNOTAS]; };
typedef struct Alumno tAlumno;

void pedirNotas(tAlumno c[]);
void pedirNombres(tAlumno c[]);
float * calcularMedia(tAlumno c[]);
void mostrarMedia(float media[]);

main () {
  tAlumno clase[NUMALUMNOS];
  float *media;
  
  pedirNombres (clase);
  pedirNotas (clase);
  media=calcularMedia (clase);
  mostrarMedia(media);
  
  system("pause");
}
void pedirNombres(tAlumno c[]){
  int i,j;
  
  for (i=0;i<NUMALUMNOS; i++) {
      printf ("Dar el nombre del alumno %d:",i);
      fgets (c[i].nombre,20,stdin);
      c[i].nombre[strlen(c[i].nombre)-1]='\0';  //elimino el salto de línea
    }
}
void pedirNotas(tAlumno c[]){
  int i,j;
  
  for (i=0;i<NUMALUMNOS; i++)
    for (j=0; j<NUMNOTAS;j++) {
      printf ("Dar la nota %d del alumno %s(decimales con .):",j,c[i].nombre );
      scanf ("%f", &(c[i].notas[j]) );
    }
}
float * calcularMedia(tAlumno c[]){
  int i,j;
  float suma,*media;
  
  media=(float *)malloc(NUMALUMNOS*sizeof(float));
  for (i=0;i<NUMALUMNOS; i++) {
    suma=0;
    for (j=0; j<NUMNOTAS;j++) 
      suma=suma+c[i].notas[j];
    media[i]=suma/NUMNOTAS;
  }  
  return media;
}
void mostrarMedia(float media[]){
  int i,j;
  
  for (i=0;i<NUMALUMNOS; i++)
    printf ("Nota media del alumno %d=%f\n",i,media[i]);
}
