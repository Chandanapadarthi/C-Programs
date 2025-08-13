// Save a file

#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fpnames;
	char name[20];
	fpnames = fopen("Names.txt", "a+");
	if (fpnames == NULL) {
		printf("File couldn't be opened.\n");
		return 1;
	} else {
		printf("File is opened now.\n");
		printf("Enter a name: ");
		fgets(name, sizeof(name), stdin);
		name[strlen(name) - 1] = '\0';
		fprintf(fpnames, "%s\n", name);
	}
	// fclose(fpnames);
	printf("Successfully saved the file.");

	rewind(fpnames);
	printf("\nReading the names from the file.");
	while (fgets(name, sizeof(name), fpnames) != NULL) {
		printf("\n%s", name);
	}

}