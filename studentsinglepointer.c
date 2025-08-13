// Read and print names, m subjects names and marks of n students using single pointer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 20
void removeNewLine(char *);

int main()
{
    int studentCount, subjectCount;
    printf("Reading and Printing the student names and their marks.");
    printf("\nHow many students are there? ");
    scanf("%d", &studentCount);

    printf("Enter the total number of subjects: ");
    scanf("%d", &subjectCount);
    getchar();
    printf("\n");
    char *studentNames = (char*) malloc (studentCount * MAX_LENGTH);
    for(int studentCounter = 0; studentCounter < studentCount; studentCounter++) {
        printf("Enter the name of student-%d: ", studentCounter + 1);
        fgets(studentNames + (studentCounter * MAX_LENGTH), MAX_LENGTH, stdin);
        removeNewLine(studentNames + (studentCounter * MAX_LENGTH));
    }
    printf("\n");

    char *subjects = (char*) malloc (subjectCount * MAX_LENGTH);
    for(int subjectCounter = 0; subjectCounter < subjectCount; subjectCounter++) {
        printf("Enter subject-%d name: ", subjectCounter + 1);
        fgets(subjects + (subjectCounter * MAX_LENGTH), MAX_LENGTH, stdin);
        removeNewLine(subjects + (subjectCounter * MAX_LENGTH));
    }
    printf("\n");

    int **subjectMarks = (int **) malloc (studentCount * sizeof(int *));
    for(int studentCounter = 0; studentCounter < studentCount; studentCounter++) {
        subjectMarks[studentCounter] = (int *) malloc (subjectCount * sizeof(int));
    }
    for(int studentCounter = 0; studentCounter < studentCount; studentCounter++) {
        for(int subjectCounter = 0; subjectCounter < subjectCount; subjectCounter++) {
            printf("Enter the marks of %s in %s: ", studentNames + (studentCounter * MAX_LENGTH), subjects + (subjectCounter * MAX_LENGTH));
            scanf("%d", &subjectMarks[studentCounter][subjectCounter]);
        }
        printf("\n");
    }
    printf("\n%*s", MAX_LENGTH, "Student Name");
    for(int subjectCounter = 0; subjectCounter < subjectCount; subjectCounter++) {
        printf("%*s", MAX_LENGTH, &subjects[subjectCounter]);
    }
    
    for(int studentCounter = 0; studentCounter < studentCount; studentCounter++) {
        printf("\n%*s", MAX_LENGTH, studentNames + (studentCounter * MAX_LENGTH));    
        for(int subjectCounter = 0; subjectCounter < subjectCount; subjectCounter++) {
            printf("%*d", MAX_LENGTH, subjectMarks[studentCounter][subjectCounter]);
        }
    }
}

void removeNewLine(char *string)
{
    string[strlen(string) - 1] = '\0';
}