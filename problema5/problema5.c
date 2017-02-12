#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"
#include "ficheros.h"


int main(int argc, char *argv[])

{
	char * sText, * sLowerText, * sUpperText, * sFile, * sPalindrome;

	if(argc < 2)
	{
		printf("Argumentos insuficientes\n");
		return -1;
	}
	sFile = argv[1];
	printf("leyendo %s\n",sFile);

	sText = leer(sFile);
	sUpperText = upperCase(sText);
	sLowerText = lowerCase(sText);
	sPalindrome = palindrome(sText);


	printf("%s\n",sText);
	printf("Mayúsculas: %s\n",sUpperText);
	printf("Minúsculas: %s\n",sLowerText);
	printf("Palindromo: %s\n",sPalindrome);
	writeWords(sText);

	free(sUpperText);
	free(sLowerText);
	free(sPalindrome);

    return 0;
}


