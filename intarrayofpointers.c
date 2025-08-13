// Read integer values using array of pointers

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int employeesCount;
	printf("Enter the total count of Employees: ");
	scanf("%d", &employeesCount);
	int *salaries[employeesCount];
	for (int employeesCounter = 0; employeesCounter < employeesCount; employeesCounter++) {
		salaries[employeesCounter] = (int *) malloc (sizeof(int));
		printf("Enter the salary of employee-%d: ", employeesCounter + 1);
		scanf("%d", &salaries[employeesCounter]);
	}
	for (int employeesCounter = 0; employeesCounter < employeesCount; employeesCounter++) {
		printf("salary of employee-%d is %d.\n", employeesCounter + 1, salaries[employeesCounter]);
	}
}