// Print the biggest and the smallest of the given N numbers

#include <stdio.h>

void main() {
	int count;
	printf("How many numbers do you want to read? ");
	scanf("%d", &numberCount);
	int numbers[numberCount];
	for(int numberCounter = 0; numberCounter < numberCount; numberCounter++) {
		scanf("%d", &numbers[numberCounter]);
	}
	int biggest = numbers[0];
	int smallest = numbers[0];
	for(int numberCounter = 1; numberCounter < numberCount; numberCounter++) {
		if(smallest > numbers[numberCounter]) {
			smallest = numbers[numberCounter];
		}
		if(biggest < numbers[numberCounter]) {
			biggest = numbers[numberCounter];
		}
	}
	printf("The biggest and the smallest of the given %d numbers are %d, %d", count, biggest, smallest);

}