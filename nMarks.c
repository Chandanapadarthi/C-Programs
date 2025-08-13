// Read and print N marks with arrays and malloc

#include <stdio.h>

int main() {
	int marksCount;
	printf("How many marks would you like to read and print? ");
	scanf("%d", &marksCount);
	int marks[marksCount];
	for(int marksCounter = 1; marksCounter <= marksCount; marksCounter++) {
		printf("Enter number %d: ", marksCounter);
		scanf("%d", &marks[marksCounter]);
	}
	printf("The %d marks you entered are ", marksCount);
	for(int marksCounter = 1; marksCounter <= marksCount; marksCounter++) {
		if(marksCounter < marksCount) {
			printf("%d, ", marks[marksCounter]);
		} else {
			printf("%d.", marks[marksCounter]);
		}
	}
}