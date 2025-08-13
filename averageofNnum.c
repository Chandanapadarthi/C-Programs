// Print average of the n numbers

#include <stdio.h>

void main() {
	printf("Printing the average of N numbers.");
	int number = 1, count = 0, sum = 0;
	char toContinue = 'y';
	while(toContinue == 'y') {
		count++;
		printf("\nEnter number %d: ", count);
		scanf("%d", &number);
		sum += number;
		printf("\nDo you want to continue? Enter y to continue: ");
		scanf(" %c", &toContinue);
	}
	float average = (float)sum / count;
	printf("\nAverage of the given %d numbers is %.2f", count, average);
}
