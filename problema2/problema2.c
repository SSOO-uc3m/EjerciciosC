#include <stdio.h>
const int NAME_SIZE = 10;

int main()
{
	char name [NAME_SIZE];

	printf("Whats your name?\n");

	scanf("%s",name);

    printf("Hello %s\n",name);

    return 0;
}
