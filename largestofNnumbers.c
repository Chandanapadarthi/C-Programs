// Print largest of N numbers

#include <stdio.h>

void main(){
	int count;
	printf("Enter how many numbers you want to read: ");
	scanf("%d", &count);
	int numbers[count];
	for(int numberCounter = 0; numberCounter < count; numberCounter++) {
		scanf("%d", &numbers[numberCounter]);
	}
	int largest = 0;
	for(int numberCounter = 0; numberCounter < count; numberCounter++) {
		if(largest < numbers[numberCounter]) {
			largest = numbers[numberCounter];
		}
	}
	printf("The largest of the given %d numbers is %d", count, largest);
}