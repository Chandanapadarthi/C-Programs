// Read and save a bank customer's details into a file.

#include <stdio.h>
#include <string.h>

struct bankCustomerDetails
{
	char accountNo[15];
	char name[50];
	char gender;
	char phoneNo[15];
};

int main()
{
	FILE *fpBankCustomer;
	struct bankCustomerDetails customer;
	fpBankCustomer = fopen("BankCustomerDetails.dat", "ab+");
	if (fpBankCustomer == NULL) {
		printf("File could not be opened.\n");
	} else {
		printf("File is now opened.\n");
		printf("Enter the bank account number of the customer: ");
		scanf("%s", &customer.accountNo);
		fflush(stdin);
		printf("Enter the name of the customer: ");
		fgets(customer.name, sizeof(customer.name), stdin);
	 	customer.name[strlen(customer.name) - 1] = '\0';
		printf("Enter the gender of the customer(M/F): ");
		scanf("%c", &customer.gender);
		printf("Enter the customer's phone number: ");
		scanf("%s", &customer.phoneNo);
		fwrite(&customer, sizeof(struct bankCustomerDetails), 1, fpBankCustomer);
	}
	// fclose(fpBankCustomer);
	printf("The customer details are successfully saved into a file.");
	rewind(fpBankCustomer);
	while (fread(&customer, sizeof(customer), 1, fpBankCustomer)) {
		printf("\nBank Account Number: %s\nName: %s\nGender: %c\nPhone Number: %s", customer.accountNo, customer.name, customer.gender, customer.phoneNo);
	}
}