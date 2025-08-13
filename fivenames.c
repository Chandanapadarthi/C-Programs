// Read and print five names

#include <stdio.h>

int main(void) {
	char names[5][50];
	printf("Enter any 5 names to read and print.\n");
	for(int nameCounter = 1; nameCounter <= 5; nameCounter++) {
		printf("Enter name %d: ", nameCounter);
		scanf("%s", &names[nameCounter]);
	}
	printf("The 5 names are ");
	for(int nameCounter = 1; nameCounter <= 5; nameCounter++) {
		if(nameCounter < 5){
			printf("%s, ", names[nameCounter]);
		}
		else
			printf("%s.", names[nameCounter]);
	}
}