// Use a single pointer to read and print names of n students

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 20
void main()
{
    int studentsCount, subjectCount;

    printf("Reading and Printing students names using pointers.\n");

    printf("Enter the total number of students: ");
    scanf("%d", &studentsCount);
    getchar();
    char *names = (char *) malloc (studentsCount * MAX_LENGTH);
    for(int studentCounter = 0; studentCounter < studentsCount; studentCounter++) {
        printf("Enter the name of student-%d: ", studentCounter + 1);
        fgets(names + (studentCounter * MAX_LENGTH), MAX_LENGTH, stdin);
    }
    for(int studentCounter = 0; studentCounter < studentsCount; studentCounter++) {
        printf("%s\n", names + (studentCounter * MAX_LENGTH));
    }
}