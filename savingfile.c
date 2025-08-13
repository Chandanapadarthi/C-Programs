// Read a name and save it into a file

#include <stdio.h>
#include <string.h>
#define nameLength 50
void main() 
{
	char name[nameLength];
	FILE* filePointer;
	printf("Enter a name to save it into a file: ");
	fgets(name, nameLength, stdin);
	filePointer = fopen("cfile.txt", "w");
	if(filePointer == NULL) {
		printf("File is not opened.");
	} else {
		printf("File is opened now.\n");
		fputs(name, filePointer);
		fputs("\n", filePointer);
	}
	fclose(filePointer);
	printf("The given name successfully saved into cfile.txt.");
}