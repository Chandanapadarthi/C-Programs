// Employee details in a company

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NAME_LEN 50
#define MAX_ID_LEN 10
#define ID_SPACE 10
#define MAX_SPACE 30

struct employeeDetails;
int addNewEmployee(char*, struct employeeDetails);
int showAllEmployees(char*, struct employeeDetails);
int updateEmployeeDetails(char*, struct employeeDetails);
int deleteEmployee(char*, struct employeeDetails);

struct employeeDetails
{
    char employeeID[MAX_ID_LEN];
    char employeeName[MAX_NAME_LEN];
    char department[MAX_NAME_LEN];
    float employeeSalary;
    char employeeStatus;
};

int addNewEmployee(char *fileName, struct employeeDetails employee)
{
    printf("Enter the employee ID: ");
    scanf("%s", employee.employeeID);
    fflush(stdin);
    printf("Enter the employee name: ");
    fgets(employee.employeeName, sizeof(employee.employeeName), stdin);
    employee.employeeName[strlen(employee.employeeName) - 1] = '\0';
    printf("Enter the department of the employee: ");
    scanf("%s", employee.department);
    printf("Enter the salary of the employee: ");
    scanf("%f", &employee.employeeSalary);
    employee.employeeStatus = 'A';

    FILE *fpEmployee = fopen(fileName, "ab+");
    if (fpEmployee == NULL) {
        printf("\nFile couldn't be opened.");
        return -1;
    }

    fwrite(&employee, sizeof(employee), 1, fpEmployee);
    fclose(fpEmployee);
    printf("\nNew Employee is successfully added!");
}

int showAllEmployees(char *fileName, struct employeeDetails employee)
{
    FILE *fpEmployee = fopen(fileName, "rb+");
    if (fpEmployee == NULL) {
        printf("\nFile couldn't be opened!");
        return -1;
    }
    printf("\n\tTecnics Employees Data\n");
    printf("\n%*s%*s%*s%*s%*s", ID_SPACE, "Employee Id", MAX_SPACE, "Employee Name", MAX_SPACE, "Department", MAX_SPACE, "Salary", MAX_SPACE, "Status");
    printf("\n----------------------------------------------------------------------------------------------------------------");
    while (fread(&employee, sizeof(struct employeeDetails), 1, fpEmployee)) {
        printf("\n%*s%*s%*s%*.2f%*c", ID_SPACE, employee.employeeID, MAX_SPACE, employee.employeeName, MAX_SPACE, employee.department, MAX_SPACE, employee.employeeSalary, MAX_SPACE, employee.employeeStatus);
    }
}

int updateEmployeeDetails(char *fileName, struct employeeDetails employee)
{
    char empID[MAX_ID_LEN];
    printf("\nEnter the employee ID to update details: ");
    scanf("%s", empID);
    FILE *fpEmployee = fopen(fileName, "rb+");
    bool found = false;
    while (fread(&employee, sizeof(employee), 1, fpEmployee)) {
        if(!strcmp(employee.employeeID, empID)) {
            found = true;
            break;
        }
    }
    
    if(!found) {
        printf("\nEnter a valid employee ID!");
        return -1;
    }

    int option;
    while (1) {
        printf("\n1. Update Employee ID\n2. Change Employee Name\n3. Update employee's department\n4. Update salary\n5. No more Updates\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1: printf("\nEnter the new ID of the employee: ");
                    scanf(" %s", employee.employeeID);
                    break;
            case 2: printf("\nEnter the new name of the employee: ");
                    fflush(stdin);
                    fgets(employee.employeeName, sizeof(employee.employeeName), stdin);
                    employee.employeeName[strlen(employee.employeeName) - 1] = '\0';
                    break;
            case 3: printf("\nEnter the new salary of the employee: ");
                    scanf(" %f", &employee.employeeSalary);
                    break;
            case 4: printf("\nEnter the updated department of the employee: ");
                    scanf(" %s", employee.department);
                    break;
            case 5: fseek(fpEmployee, -(long) (sizeof(employee)), SEEK_CUR);
                    fwrite(&employee, sizeof(employee), 1, fpEmployee);
                    fclose(fpEmployee);
                    printf("\nUpdates are successfully made!\n");
                    return 0;
            default: printf("nEnter a valid option!");
        }
    }
}

int deleteEmployee(char *fileName, struct employeeDetails employee)
{
    char empID[MAX_ID_LEN];
    printf("\nEnter the employee ID to delete: ");
    scanf("%s", empID);
    FILE *fpEmployee = fopen(fileName, "rb+");
    while (fread(&employee, sizeof(employee), 1, fpEmployee)) {
        if(!strcmp(employee.employeeID, empID)) {
            employee.employeeStatus = 'D';
            fseek(fpEmployee, -(long)(sizeof(struct employeeDetails)), SEEK_CUR);
            fwrite(&employee, sizeof(employee), 1, fpEmployee);
            break;
        }
    }
    fclose(fpEmployee);
    printf("\nEmployee details are successfully deleted!");

}

int main()
{
    char choice;
    char fileName[] = "EmployeeData.dat";
    struct employeeDetails employee;
    printf("Welcome to Tecnics Employee Database.");        
    while(1)
    {
        printf("\n1. Create new Employee\n2. Retrieve all employees data\n3. Update employee data\n4. Delete employee\n5. Exit the database\n");
        printf("\nEnter your choice: ");
        scanf(" %d", &choice);

        switch(choice)
        {
            case 1: addNewEmployee(fileName, employee);
                    break;
            case 2: showAllEmployees(fileName, employee);
                    break;
            case 3: updateEmployeeDetails(fileName, employee);
                    break;
            case 4: deleteEmployee(fileName, employee);
                    break;
            case 5: printf("\nYou have exited the database!");
                    return 0;
            default: printf("\nEnter a valid choice!\n");
                    break;
        }
    }
    return 0;
}