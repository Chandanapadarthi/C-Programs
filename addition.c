// Adding  two numbers

#include <stdio.h>

void main() {
	int num1, num2, sum;
	printf("Addition of two numbers\n");
	printf("Enter the first number: ");
	scanf("%d", &num1);
	printf("Enter the second number: ");
	scanf("%d", &num2);
	sum = num1 + num2;
	printf("Sum of %d and %d is: %d", num1, num2, sum);
	
}