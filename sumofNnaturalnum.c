// Print sum of N natural numbers

#include <stdio.h>

void main() {
	int count, sum = 0;
	printf("How many natural numbers do you want to add? ");
	scanf("%d", &count);
	for(int numberCounter = 1; numberCounter <= count; numberCounter++) {
		sum += numberCounter;
	}
	printf("Sum of %d natural numbers is %d", count, sum);
}