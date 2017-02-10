
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

	sLowerCase = copyString(string);

	return sLowerCase;

}
//realiza el palíndromo de la cadena de caracteres (escribe todos los caracteres al revés)
//TODO
char * palindrome(char * string){
	char * sPalindrome;
	sPalindrome = copyString(string);
	return sPalindrome;
}
//escribe una palabra por línea.
//TODO
void writeWords(char * string){
	
}