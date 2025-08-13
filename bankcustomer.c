// Read and print a bank customer details using structure

#include <stdio.h>
#include <string.h>

struct bankCustomer
{
	char accountNo[15];
	char name[50];
	char gender;
	char phoneNo[15];
};

void main()
{
	struct bankCustomer customer;
	printf("Enter the customer's account number: ");
	scanf("%s", &customer.accountNo);
	fflush(stdin);
	printf("Enter the customer's name: ");
	fgets(customer.name, sizeof(customer.name), stdin);
	customer.name[strlen(customer.name) - 1] = '\0';
	printf("Enter the customer's gender: ");
	scanf("%c", &customer.gender);
	printf("Enter the customer's phone Number: ");
	scanf("%s", &customer.phoneNo);
	printf("\nThe customer's details are");
	printf("\nBank Account No: %s\nName: %s\nGender: %c\nPhone Number: %s", customer.accountNo, customer.name, customer.gender, customer.phoneNo);
}