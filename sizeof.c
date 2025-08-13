#include <stdio.h>

void main()
{
    int balance;
    int *marks;
    char answer;
    char name[20];
    char *city;

    printf("Sizeof balance: %d\nsizeof int: %d\nsizeof int*: %d\nsizeof marks: %d\nsizeof answer: %d\nsizeof name: %d\nsizeof city: %d\nsizeof char*: %d", sizeof(balance), sizeof(int), sizeof(int*), sizeof(marks), sizeof(answer), sizeof(name), sizeof(city), sizeof(char*));
}