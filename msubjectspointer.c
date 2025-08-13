//Read and Print names, m subject names and marks of n students using pointer to pointer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20  

int main() {
    int studentsCount, subjectCount;

    printf("Reading and Printing students names and subject marks using pointers.\n");

    printf("Enter the total number of students: ");
    scanf("%d", &studentsCount);

    printf("How many subjects would you like to read? ");
    scanf("%d", &subjectCount);

    char **subjects = (char **)malloc(subjectCount * sizeof(char *));
    for (int subjectCounter = 0; subjectCounter < subjectCount; subjectCounter++) {
        subjects[subjectCounter] = (char *)malloc(MAX_LENGTH * sizeof(char));
        printf("Enter the name of subject-%d: ", subjectCounter + 1);
        scanf("%s", subjects[subjectCounter]);
    }

    char **names = (char **)malloc(studentsCount * sizeof(char *));
    for (int studentCounter = 0; studentCounter < studentsCount; studentCounter++) {
        names[studentCounter] = (char *)malloc(MAX_LENGTH * sizeof(char));
        printf("Enter the name of student-%d: ", studentCounter + 1);
        scanf("%s", names[studentCounter]);
    }

    int **marks = (int **)malloc(studentsCount * sizeof(int *));
    for (int studentCounter = 0; studentCounter < studentsCount; studentCounter++) {
        marks[studentCounter] = (int *)malloc(subjectCount * sizeof(int));
    }

    for (int studentCounter = 0; studentCounter < studentsCount; studentCounter++) {
        for (int subjectCounter = 0; subjectCounter < subjectCount; subjectCounter++) {
            printf("Enter the marks of %s in %s: ", names[studentCounter], subjects[subjectCounter]);
            scanf("%d", &marks[studentCounter][subjectCounter]);
        }
    }

    printf("\n%*s", MAX_LENGTH, "Student Name");
    for (int subjectCounter = 0; subjectCounter < subjectCount; subjectCounter++) {
        printf("%*s", MAX_LENGTH, subjects[subjectCounter]);
    }

    for (int studentCounter = 0; studentCounter < studentsCount; studentCounter++) {
        printf("\n%*s", MAX_LENGTH, names[studentCounter]);
        for (int subjectCounter = 0; subjectCounter < subjectCount; subjectCounter++) {
            printf("%*d", MAX_LENGTH, marks[studentCounter][subjectCounter]);
        }
    }
    printf("\n");

    // Free allocated memory
    // for (int i = 0; i < subjectCount; i++) {
    //     free(subjects[i]);
    // }
    // free(subjects);

    // for (int i = 0; i < studentsCount; i++) {
    //     free(names[i]);
    //     free(marks[i]);
    // }
    // free(names);
    // free(marks);

    return 0;
}
