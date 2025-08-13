// Print sum of all command line arguements

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int sum = 0;
	for(int counter = 1; counter < argc; counter++) {
		sum = sum + atoi(argv[counter]);
	}
	printf("The sum of %d command line arguements is %d.", argc - 1, sum);
}