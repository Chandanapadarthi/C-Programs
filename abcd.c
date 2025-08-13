// Print ABCD using %d

#include <stdio.h>

void main()
{
	char var = 'ABCD';
	// int abcd = 1094861636;
	int abcd = 1094861636;
	// printf("%s\n%d", var, var);
	printf("\n%s", &abcd);
}