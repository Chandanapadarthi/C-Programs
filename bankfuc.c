// Use functions to create and display bank customer details

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15

struct bankCustomerDetails;
int createCustomer(char*);
int showCustomerDetails(char*);
int updateCustomerDetails(char*);
void updateName(struct bankCustomerDetails*);
void updatePhoneNo(struct bankCustomerDetails*);
void updateBalance(struct bankCustomerDetails*);
void updateGender(struct bankCustomerDetails*);
int deleteAccount(char*);

struct bankCustomerDetails
{
	char accountNo[MAX_NUM_LEN];
	char name[MAX_NAME_LEN];
	char gender;
	char phoneNo[MAX_NUM_LEN];
	float balance;
	char accountStatus;
};

int createCustomer(char fileName[])
{
	FILE *fpcustomer = fopen(fileName, "ab+");
	struct bankCustomerDetails customer;
	if (fpcustomer == NULL) {
		printf("\nFile could not be opened.");
		return -1;
	} 

	printf("File is now opened.\n");
	printf("Enter the bank account number of the customer: ");
	scanf("%s", customer.accountNo);
	fflush(stdin);
	printf("Enter the name of the customer: ");
	fgets(customer.name, sizeof(customer.name), stdin);
	customer.name[strlen(customer.name) - 1] = '\0';
	printf("Enter the gender of the customer(M/F): ");
	scanf("%c", &customer.gender);
	printf("Enter the customer's phone number: ");
	scanf("%s", customer.phoneNo);
	printf("Enter the balance of the customer: ");
	scanf("%f", &customer.balance);
	customer.accountStatus = 'A';
	fwrite(&customer, sizeof(struct bankCustomerDetails), 1, fpcustomer);
	fclose(fpcustomer);
	printf("\nSuccessfully created the customer's account.\n");
}

int showCustomerDetails(char fileName[])
{
	FILE *fpcustomer = fopen(fileName, "rb+");
	struct bankCustomerDetails customer;
	if (fpcustomer == NULL) {
		printf("\nFile couldn't be opened.");
		return -1;
	}
	int customerCounter = 1;
	while(fread(&customer, sizeof(customer), 1, fpcustomer)) {
		if (customer.accountStatus == 'A') {
			printf("\n");
			printf("\n------- Customer-%d Details -------\nBank Account Number: %s\nCustomer Name: %s\nCustomer Gender: %c\nCustomer Phone Number: %s\nAccount Balance: %.2f\nAccount Status: %c\n", customerCounter++, customer.accountNo, customer.name, customer.gender, customer.phoneNo, customer.balance, customer.accountStatus);
		}
	}
	fclose(fpcustomer);
	printf("\nAll Customer Details are successfully retrieved.\n");
}

int updateCustomerDetails(char fileName[]) 
{
	char currentAccountNo[MAX_NUM_LEN];
	struct bankCustomerDetails customer;
	printf("\nEnter the account number of the customer to update account details: ");
	scanf("%s", currentAccountNo);
	FILE *fpcustomer = fopen(fileName, "rb+");
	if (fpcustomer == NULL) {
		printf("\nFile couldn't be opened.");
		return -1;
	}

	bool found = false;
	while(fread(&customer, sizeof(struct bankCustomerDetails), 1, fpcustomer)) {
		if (strcmp(customer.accountNo, currentAccountNo) == 0) {
			found = true;
			break;
		}
	}
	
	if(!found) {
		printf("\nEnter a valid account number!\n");
		return -1;
	}
	int option;
	long offset = sizeof(customer);

	while(1) {
		printf("\n1. Changing the account holder name\n2. Updating the phone number\n3. Updating the balance\n4. Update Gender\n5. No more updates\n");
		printf("\nEnter you choice: ");
		scanf("%d", &option);
		fflush(stdin);
		switch (option)
		{
		case 1: updateName(&customer);
				break;
		case 2: updatePhoneNo(&customer);
				break;
		case 3: updateBalance(&customer);
				break;
		case 4: updateGender(&customer);
				break;
		case 5:	fseek(fpcustomer, -offset, SEEK_CUR);
				fwrite(&customer, sizeof(customer), 1, fpcustomer);
				fclose(fpcustomer);
				printf("\nUpdates are successfully made!\n");
				return 0;
		default: printf("\nEnter valid option!");
				break;
		}
	}
}

void updateName(struct bankCustomerDetails *customer)
{
	printf("\nEnter the new name: ");
	fgets(customer->name, sizeof(customer->name), stdin);
	customer->name[strlen(customer->name) - 1] = '\0';
	printf("\nCustomer name is updated successfully.\n");
}

void updatePhoneNo(struct bankCustomerDetails *customer)
{
	printf("Enter the new phone number: ");
	scanf("%s", customer->phoneNo);
	printf("\nPhone number is updated successfully.\n");
}

void updateBalance(struct bankCustomerDetails *customer)
{
	printf("\nEnter the new balance: ");
	scanf("%f", &customer->balance);
	printf("\nAccount balance is updated!\n");
}

void updateGender(struct bankCustomerDetails *customer)
{
	if(customer -> gender == 'M') {
		customer->gender = 'F';
	}
	else {
		customer->gender = 'M';
	}
	printf("\nSuccessfully updated the gender!\n");
}

int deleteAccount(char fileName[])
{
	FILE *fpcustomer = fopen(fileName, "rb+");
	struct bankCustomerDetails customer;
	char accountNumber[MAX_NUM_LEN];
	printf("\nEnter the customer account number: ");
	scanf("%s", accountNumber);
	if(fileName == NULL) {
		printf("\nFile couldn't be opened.");
		return -1;
	}

	bool found = false;
	while (fread(&customer, sizeof(struct bankCustomerDetails), 1, fpcustomer))
	{
		if(!strcmp(customer.accountNo, accountNumber)) {
			found = true;
			break;
		}
	}
	if(!found) {
		printf("\nEnter a valid account number!\n");
		return -1;
	}
	customer.accountStatus = 'D';
	long offset = sizeof(struct bankCustomerDetails);
	fseek(fpcustomer, -offset, SEEK_CUR);
	fwrite(&customer, sizeof(struct bankCustomerDetails), 1, fpcustomer);
	fclose(fpcustomer);
	printf("\nThe customer account is deleted successfully!\n");
}

int main()
{
	int choice;
	char fileName[] = "BankCustomerDetails.dat";
	printf("Creating and Retrieving Bank Customer Details\n");
	while(1) {
		printf("\n1. Open customer account\n2. Retrieve all customers details\n3. Update the customer details\n4. Close an account\n5. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{	
			case 1: createCustomer(fileName);
					break;
			case 2: showCustomerDetails(fileName);
					break;
			case 3: updateCustomerDetails(fileName);
					break;
			case 4: deleteAccount(fileName);
					break;
			case 5: printf("\nYou are exiting the program.");
					return 0;
			default: printf("\nEnter a valid choice!");
		}
	}
	return 0;
}