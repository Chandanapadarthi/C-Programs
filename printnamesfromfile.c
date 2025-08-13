// Print all the names from a file.

#include <stdio.h>

int main()
{
	FILE* fptr;
	char names[25];
	printf("Printing the names from a saved file.\n");
	fptr = fopen("cfile.txt", "r");
	if(fptr == NULL) {
		printf("File not opened.");
		return 1;
	} else {
		printf("Reading from the file.\nThe names from the file are:\n");
		while(fgets(names, sizeof(names), fptr) != NULL) {
			printf("%s", names);
		}
	}
	fclose(fptr);
	printf("All the names are successfully printed from cfile.txt.");
}