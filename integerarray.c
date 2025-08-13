// Integer array

#include <stdio.h>

void main()
{
    int employeeCount;
    printf("Enter the total number of Employees: ");
    scanf("%d", &employeeCount);
    int employeesSalaries[employeeCount];
    for(int salaryCounter = 0; salaryCounter < employeeCount; salaryCounter++) {
        printf("Enter the salary of employee-%d: ", salaryCounter + 1);
        scanf("%d", &employeesSalaries[salaryCounter]);
    }
    printf("The salaries of the employees are");
    for(int salaryCounter = 0; salaryCounter < employeeCount; salaryCounter++) {
        printf("\n%d", employeesSalaries[salaryCounter]);
    }

}