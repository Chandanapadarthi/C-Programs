// Save a name into a file using fputc, fputs, fprintf, fwrite

#include <stdio.h>
#include <string.h>
#define length 25

int main() 
{
	char name[length];
	FILE *fptr;
	fptr = fopen("namesavingfile.txt", "w");
	if(fptr == NULL) {
		printf("Couldn't open the file.");
	} else {
		printf("Enter a name to save into a file: ");
		fgets(name, length, stdin);
		name[strlen(name) - 1] = '\0';
		for(int lengthCounter = 0; lengthCounter < strlen(name); lengthCounter++) {
			fputc(name[lengthCounter], fptr);
		}
		fputc('\n', fptr);
		fputs(name, fptr);
		fputc('\n', fptr);
		fprintf(fptr, name);
		fputc('\n', fptr);
		fwrite(name, sizeof(name), 1, fptr);
	}
	fclose(fptr);
	printf("Name is successfully saved into a file.\nFile is now closed.");
}