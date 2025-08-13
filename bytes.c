// Print the bytes of the number

#include <stdio.h>

int main()
{
    // int num = 65;
    // char *name = (char*) &num;
    // for(int i = 0; i < 4; i++) {
    //     printf("%d ", name[i]);
    // }
    char alph[] = "ABCD";
    int num = (int) alph;
    printf("%s\n", alph[0]);
    int *intpointer;
    char *charpointer;
    printf("%u\n%u", intpointer, charpointer);
}