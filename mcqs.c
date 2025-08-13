// Read and Print answers of 10MCQs of 5 students

#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10

void main()
{
	int studentCount = 5;
	printf("Reading and Printing the answers of students in a MCQs test.\n");
	char **answers = (char**) malloc (studentCount * sizeof(char*));
	for (int studentCounter = 0; studentCounter < studentCount; studentCounter++) {
		answers[studentCounter] = (char *) malloc (MAX_LEN * sizeof(char));
		for (int mcqCounter = 0; mcqCounter < MAX_LEN; mcqCounter++) {
			printf("Enter the answer of MCQ-%d of student-%d: ", mcqCounter + 1, studentCounter + 1);
			scanf(" %c", &answers[studentCounter][mcqCounter]);
		}
		printf("\n");
	}
	printf("\nThe answers of %d students in %dMCQs are", studentCount, MAX_LEN);
	for (int studentCounter = 0; studentCounter < studentCount; studentCounter++) {
		printf("\nThe answers of student-%d are", studentCounter + 1);
		for (int mcqCounter = 0; mcqCounter < MAX_LEN; mcqCounter++) {
			printf(" %c", answers[studentCounter][mcqCounter]);
		}
	}
}