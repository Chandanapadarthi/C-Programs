// Read and print N names using array

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define nameLength 100

int main(void) {
	int namesCount;
	printf("How many names do you want to read and print? ");
	scanf("%d", &namesCount);
	getchar();
	char names[namesCount][nameLength];
	for(int nameCounter = 0; nameCounter < namesCount; nameCounter++) {
		printf("Enter name %d: ", nameCounter + 1);
		fgets(names[nameCounter], nameLength, stdin);
		size_t length = strlen(names[nameCounter]);
		if(length > 0 && names[nameCounter][length - 1] == '\n') {
			names[nameCounter][length - 1] = '\0';
		}
	}
	printf("The %d names you entered are:", namesCount);
	for(int nameCounter = 0; nameCounter < namesCount; nameCounter++) {
		printf("\n%s", names[nameCounter]);
	}
}