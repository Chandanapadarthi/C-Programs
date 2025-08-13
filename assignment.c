#include <stdio.h>

void print(char *name)
{
	name = "Chandana";
	printf("Name: %s", name);
}

int main()
{
	char *name;
	print(name);
	return 0;
}