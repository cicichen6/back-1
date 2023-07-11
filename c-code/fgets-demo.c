#include "stdio.h"

int main()
{
	char str[20];
	fgets(str, sizeof(str), stdin);

	char * pStr = str;

	printf("The first word is: %c", *pStr);

	return 0;
}
