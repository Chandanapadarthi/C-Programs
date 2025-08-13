// Read and Print N student names using array of pointers

#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10

void main()
{
    int studentCount;
    printf("Reading and Printing student names using array of pointers.");
    printf("Enter the total number of students: ");
    scanf("%d", &studentCount);
    char *names[studentCount];
    for (int namesCounter = 0; namesCounter < studentCount; namesCounter++) {
        names[namesCounter] = (char*) malloc (MAX_LEN * sizeof(char));
        printf("Enter student-%d name: ", namesCounter + 1);
        scanf("%s", names[namesCounter]);
    }
    for (int namesCounter = 0; namesCounter < studentCount; namesCounter++) {
        printf("Student-%d name is %s.\n", namesCounter + 1, names[namesCounter]);
    }
}