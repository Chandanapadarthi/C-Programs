// Integer Single pointer

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int studentCount, *gradepoints;
    printf("How many students grade points would you like to read? ");
    scanf("%d", &studentCount);
    gradepoints = (int *)malloc(studentCount * sizeof(int));
    for(int studentCounter = 0; studentCounter < studentCount; studentCounter++) {
        printf("Enter the grade points of student-%d: ", studentCounter + 1);
        scanf("%d", &gradepoints[studentCounter]);
    }
    printf("The grade points of %d students are", studentCount);
    for(int studentCounter = 0; studentCounter < studentCount; studentCounter++) {
        printf("\n%d", gradepoints[studentCounter]);
    }
}