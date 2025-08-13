// Print multiplication table in reverse order

#include <stdio.h>

void main() {
	int tableNumber, rowsCount;
	printf("Enter a number to print its table in reverse order: ");
	scanf("%d", &tableNumber);
	if(tableNumber == 0) {
		printf("Enter a valid number: ");
		scanf("%d", &tableNumber);
	}
	printf("Enter number of rows you want to print: ");
	scanf("%d", &rowsCount);
	for(int rowCounter = rowsCount; rowCounter > 0; rowCounter--) {
		printf("%d X %d = %d\n", tableNumber, rowCounter, tableNumber * rowCounter);
	}
}