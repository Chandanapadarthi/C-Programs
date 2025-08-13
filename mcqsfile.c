// Read and Print the answers of 10MCQs of 5 students

#include <stdio.h>
#include <stdlib.h>
#define MAX_MCQS 10

int main()
{
    int studentCount = 5;
    char answer;
    FILE *fpAnswers = fopen("MCQsAnswers.dat", "a");
    if (fpAnswers == NULL) {
        printf("File couldn't be opened.");
        return 1;
    }
    // else {
    //     printf("File is opened now.\n");
    //     for (int studentCounter = 0; studentCounter < studentCount; studentCounter++) {
    //         for (int answerCounter = 0; answerCounter < MAX_MCQS; answerCounter++) 
    //         {
    //             printf("Enter the answer for MCQ-%d of student-%d: ", answerCounter + 1, studentCounter + 1);
    //             scanf(" %c", &answer.answers[answerCounter]);
    //         }
    //         fwrite(&answer, sizeof(answer), 1, fpAnswers);
    //         fputs("\n", fpAnswers);
    //     }
    // }

    // rewind(fpAnswers);
    printf("Each student answers for the %dMCQs are", MAX_MCQS);
    for (int studentCounter = 0; studentCounter < studentCount; studentCounter++) {
    for(int answerCounter = 0; answerCounter < MAX_MCQS; answerCounter++) 
    {
        fscanf(fpAnswers, "%c", answer);
        printf("\nThe answers of %dMCQs of student-%d are %c.\n", MAX_MCQS, studentCounter + 1, answer);
    }
    }
    fclose(fpAnswers);
    printf("\nSuccessfully read the answers of %dMCQs of %d students.", MAX_MCQS, studentCount);
}