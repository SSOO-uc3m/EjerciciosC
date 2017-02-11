
#include "cadenas.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


char * copyString (char * string){
	char * sCopy;
 	sCopy = malloc(sizeof(char) * strlen(string));
	strcpy(sCopy,string);

	return sCopy;
}



//pasa a mayúsculas todos los caracteres de la cadena
char * upperCase(char * string){
	char * sUpperCase;
	int i = 0;

	sUpperCase = copyString(string);

	while(sUpperCase[i])
  	{
      sUpperCase[i] = (char)toupper(sUpperCase[i]);
      i++;
  	}

	return sUpperCase;

}
//pasa a minúsculas todos los caracteres de la cadena
//TODO
char * lowerCase(char * string){

	char * sLowerCase;
	int i = 0;

	sLowerCase = copyString(string);

	while(sLowerCase[i])
  	{
      sLowerCase[i] = (char)tolower(sLowerCase[i]);
      i++;
  	}

	return sLowerCase;

}
//realiza el palíndromo de la cadena de caracteres (escribe todos los caracteres al revés)
char * palindrome(char * string){
	char * sPalindrome;

	sPalindrome = copyString(string);

	int i = 0, j = 0;
	char temp;
    j = strlen(sPalindrome) - 1;
 
   	while (i < j) {
      temp = sPalindrome[i];
      sPalindrome[i] = sPalindrome[j];
      sPalindrome[j] = temp;
      i++;
      j--;

   	}

	return sPalindrome;
}
//escribe una palabra por línea.
void writeWords(char * string){
  char * token;
  char * delim = " ,.-()";
  // divide un string en una serie de tokens usando el delimitador delim.
  token = strtok (string,delim);
  printf("Palabras: \n")
  while (token != NULL)
  {
    printf ("%s\n",token);
    token = strtok (NULL, delim);
  }
	
}