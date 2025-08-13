// Character Single Pointer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 25
void removeNewLine(char *);

void main()
{
    int movieCount;
    printf("How many movies are currently playing in the mall? ");
    scanf("%d", &movieCount);
    getchar();
    char *movieNames = (char *)malloc(movieCount * sizeof(char));
    for (int movieCounter = 0; movieCounter < movieCount; movieCounter++) {
        printf("Enter movie name-%d: ", movieCounter + 1);
        fgets(movieNames + movieCounter * MAX_LEN, MAX_LEN, stdin);
        removeNewLine(movieNames + movieCounter * MAX_LEN);
    }
    printf("The movies that are playing in the mall currently are");
    for (int movieCounter = 0; movieCounter < movieCount; movieCounter++) {
        printf("\n%s", movieNames + movieCounter * MAX_LEN);
    }
}

void removeNewLine(char *string) 
{
    if (strlen(string) > 0 && string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}