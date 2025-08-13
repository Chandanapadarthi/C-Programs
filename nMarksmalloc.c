// Read and Print N marks using malloc

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int marksCount;
	int* marks;
	printf("How many marks would you like to read and print? ");
	scanf("%d", &marksCount);
	marks = (int*) malloc (marksCount * sizeof(int));	
	for(int marksCounter = 0; marksCounter < marksCount; marksCounter++) {
		printf("Enter marks %d: ", marksCounter + 1);
		scanf("%d", &marks[marksCounter]);
	}
	printf("The %d marks you entered are:", marksCount);
	for(int marksCounter = 0; marksCounter < marksCount; marksCounter++) {
		printf("\n%d", marks[marksCounter]);
	}
}