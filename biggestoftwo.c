// Print the biggest of given 2 numbers

#include <stdio.h>

void main() {
	int firstNum, secondNum;
	printf("Printing the biggest of two numbers.\nEnter the first number: ");
	scanf("%d", &firstNum);
	printf("Enter the second number: ");
	scanf("%d", &secondNum);
	if(firstNum < secondNum) {
		int temp = firstNum;
		firstNum = secondNum;
		secondNum = temp;
	}
	printf("Printing the biggest number by using another variable.\n");
	printf("%d is bigger than %d.", firstNum, secondNum);
	
	//without using any other variables

	firstNum = firstNum + secondNum;
	secondNum = firstNum - secondNum;
	firstNum = firstNum - secondNum;
	printf("\nPrinting the biggest number without using any other variables.");
	printf("\n%d is bigger than %d.", secondNum, firstNum);
}