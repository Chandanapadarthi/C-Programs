// Print multiplication tables book upto given number

#include <stdio.h>

void main() {
	int endTable, rowCount;
	printf("Enter upto which table you want to print the tables book for: ");
	scanf("%d", &endTable);
	if(endTable == 0) {
		printf("Enter a valid number: ");
		scanf("%d", &endTable);
	}
	printf("Enter upto how many rows you want to print: ");
	scanf("%d", &rowCount);
	for(int tableCounter = 1; tableCounter <= endTable; tableCounter++) {
		for(int rowCounter = 1; rowCounter <= rowCount; rowCounter++) {
			printf("%d X %d = %d\n", tableCounter, rowCounter, tableCounter * rowCounter);
		}
		printf("\n");
	}
}