// Print multiplication table of a given number

#include <stdio.h>

void main() {
	int tableNumber, rows;
	printf("Enter a number to print its multiplication table: ");
	scanf("%d", &tableNumber);
	if(tableNumber == 0) {
		printf("Enter a valid number: ");
		scanf("%d", &tableNumber);
	}
	printf("Enter how many rows of the table you want to print: ");
	scanf("%d", &rows);
	for(int rowCounter = 1; rowCounter <= rows; rowCounter++) {
		printf("%d X %d = %d\n", tableNumber, rowCoutner, tableNumber * rowCounter);
	}
}