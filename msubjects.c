// Read and print names and m marks of n students

#include <stdio.h>

void main()
{
	int studentCount, subjectCount;
	printf("Reading and Printing names and m subject marks of n students.");
	printf("\nHow many students are there? ");
	scanf("%d", &studentCount);
	printf("Enter the total number of subjects: ");
	scanf("%d", &subjectCount);
	char names[studentCount][20];
	char subjects[subjectCount][15];
	int marks[studentCount][subjectCount];
	
	for(int subjectCounter = 0; subjectCounter < subjectCount; subjectCounter++) {
		printf("Enter subject-%d name: ", subjectCounter + 1);
		scanf("%s", subjects[subjectCounter]);
	}
	printf("\n");

	for(int namesCounter = 0; namesCounter < studentCount; namesCounter++) {
		printf("Enter student-%d name: ", namesCounter + 1);
		scanf("%s", names[namesCounter]);
	}
	
	printf("\n");
	for(int studentCounter = 0; studentCounter < studentCount; studentCounter++) {
		for(int subjectCounter = 0; subjectCounter < subjectCount; subjectCounter++) {
			printf("Enter the marks of %s in  %s: ", names[studentCounter], subjects[subjectCounter]);
			scanf("%d", &marks[studentCounter][subjectCounter]); 
		}
	}

	printf("\nThe %d subjects marks of %d students are\n", subjectCount, studentCount);
	int length = 20;
	printf("%*s", length, "Student Name");
	for(int subjectCounter = 0; subjectCounter < subjectCount; subjectCounter++) {
		printf("%*s", length, subjects[subjectCounter]);
	}
	for(int studentCounter = 0; studentCounter < studentCount; studentCounter++) {
		printf("\n%*s", length, names[studentCounter]);
		for(int subjectCounter = 0; subjectCounter < subjectCount; subjectCounter++) {
			printf("%*d", length, marks[studentCounter][subjectCounter]);
		}
	}
}