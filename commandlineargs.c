// Print all command line arguements.

#include <stdio.h>

int main(int argc, char *argv[]) 
{
	printf("The %d command line arguements are: ", argc);
	for(int counter = 0; counter < argc; counter++) {
		printf("\nArguement-%d: %s", counter, argv[counter]);
	}
}