// Read and print 5 marks

#include <stdio.h>

int main(void) {
	int marks[5];
	printf("Enter any 5 marks to read and print:\n");
	for(int marksCounter = 1; marksCounter <= 5; marksCounter++) {
		printf("Enter marks %d: ", marksCounter);
		scanf("%d", &marks[marksCounter]);
	}
	printf("The 5 marks are ");
	for(int marksCounter = 1; marksCounter <= 5; marksCounter++) {
		if(marksCounter < 5)
			printf("%d, ", marks[marksCounter]);
		else
			printf("%d.", marks[marksCounter]);
	}
}