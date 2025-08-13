// Read and print names and marks of n students

#include <stdio.h>

void main()
{
	int studentsCount;
	printf("How many students names and marks would you like to read and print? ");
	scanf("%d", &studentsCount);
	int marks[studentsCount];
	char names[studentsCount][20];
	for(int namesCounter = 0; namesCounter < studentsCount; namesCounter++) {
		printf("Enter student name-%d: ", namesCounter + 1);
		scanf("%s", names[namesCounter]);
	}
	printf("\n");
	for(int marksCounter = 0; marksCounter < studentsCount; marksCounter++) {
		printf("Enter student-%d marks: ", marksCounter + 1);
		scanf("%d", &marks[marksCounter]);
	}
	
	printf("\nThe marks of %d student are ", studentsCount);
	for(int studentCounter = 0; studentCounter < studentsCount; studentCounter++) {
		printf("\n%s got %d marks.", names[studentCounter], marks[studentCounter]);
	}
}