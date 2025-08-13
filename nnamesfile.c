// Print all the names into a saved file.

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int count;
	FILE* fptr;
	printf("How many names do you want to save into a file: ");
	scanf("%d", &count);
	getchar();
	char names[count][25];
	fptr = fopen("cfile.txt", "a");
	if(fptr == NULL) {
		printf("File couldn't  be opened.");
	} else {
		printf("File is opened now.\n");
		for(int counter = 1; counter <= count; counter++) {
			printf("Enter name-%d: ", counter);
			fgets(names[counter], sizeof(names), stdin);
			fputs(names[counter], fptr);
		}
	}
	fclose(fptr);
	printf("\nAll the names are successfully saved in the file.");
}