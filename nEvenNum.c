// Print N even numbers

#include <stdio.h>

void main() {
	int count, evenNumber = 0;
	printf("How many even numbers do you want to print? ");
	scanf("%d", &count);
	printf("The first %d even numbers are: ", count);
	for(int numberCounter = 0; numberCounter < count; numberCounter++) {
		evenNumber += 2;
		if(numberCounter < count - 1) printf("%d, ", evenNumber);
		else printf("%d.", evenNumber);
	}
}