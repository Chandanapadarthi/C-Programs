// Print the given name given number of times

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	printf("Printing the given name given number of times.");
	int count = atoi(argv[2]);
	for(int counter = 0; counter < count; counter++) {
		printf("\n%s", argv[1]);
	}
}