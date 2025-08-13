// Print n to the power of n

#include <stdio.h>

void main() {
	int input, powerCounter = 1;
	printf("Enter a number to calculate it to the power of itself: ");
	scanf("%d", &input);
	for(int counter = 0; counter < input; counter++) {
		powerCounter = powerCounter * input; 
	}
	printf("%d to the power of %d is %d.", input, input, powerCounter);
}