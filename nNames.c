// Read and print N names using malloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nameLength 100

int main() {
	int namesCount;
	char** names;
	printf("How many names would you like to read and print? ");
	scanf("%d", &namesCount);
	getchar();
	names = (char**) malloc(namesCount * sizeof(char*));
	for(int nameCounter = 1; nameCounter <= namesCount; nameCounter++) {
		names[nameCounter] = (char*) malloc(nameLength * sizeof(char));
		printf("Enter name %d: ", nameCounter);
		fgets(names[nameCounter], nameLength, stdin);
		
		size_t len = strlen(names[nameCounter]);
        	if (len > 0 && names[nameCounter][len - 1] == '\n') {
            		names[nameCounter][len - 1] = '\0';
        	}
	}
	printf("The %d names you entered are:", namesCount);
	for(int nameCounter = 1; nameCounter <= namesCount; nameCounter++) {
		printf("\n%s", names[nameCounter]);
	}
}