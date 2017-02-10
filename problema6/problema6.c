#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"
#include "ficheros.h"


int main(int argc, char *argv[])

{
	char * text = "";
	printf("leyendo %s\n",argv[1]);

	if (argc>1){
		text = read(argv[1]);
	}
	printf("%s\n",text);
	
    return 0;
}


