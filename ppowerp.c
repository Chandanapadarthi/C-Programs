// Print p to the power of q

#include <stdio.h>

void main() {
	int base, exponent, powerCounter = 1;
	printf("Printing the power of a given number.\nEnter the base value: ");
	scanf("%d", &base);
	printf("Enter the exponent value: ");
	scanf("%d", &exponent);
	for(int counter = 1; counter <= exponent; counter++) {
		powerCounter  = powerCounter * base;
	}
	printf("%d to the power of %d is %d", base, exponent, powerCounter);
	
}