// Read and save a bank customer details into a file using fwrite

#include <stdio.h>
#include <string.h>

struct bankCustomerDetails
{
	char customerName[25];
	char gender;
	long long phoneNo;
	long long accountNo;
};

int main() 
{
	FILE* fptr;
	struct bankCustomerDetails customer;
	printf("Enter the bank customer details:\nEnter the customer name: ");
	fgets(customer.customerName, sizeof(customer.customerName), stdin);
	customer.customerName[strcspn(customer.customerName, "\n")] = 0;
	
	printf("Enter the customer's gender(M/F) : ");
	scanf(" %c", &customer.gender);
	
	printf("Enter the cusomer's phone number: ");
	scanf(" %lld", &customer.phoneNo);
	
	printf("Enter the customer's account number: ");
	scanf("%lld", &customer.accountNo);
	
	fptr = fopen("bankcustomerB.bin", "ab+");
	if(fptr == NULL) {
		printf("File is not opened.");
		return 1;
	} else {
		printf("File is opened.");
		fwrite(&customer, sizeof(struct bankCustomerDetails), 1, fptr);
	}
	printf("\nSuccessfully saved the details into a binary file.");

	rewind(fptr);
	printf("\nReading the customer details from the binary fie.");
	printf("\nName\t\t\tGender\t\tPhone No\t\tAccount No");
	
	while(fread(&customer, sizeof(struct bankCustomerDetails), 1, fptr)){
		printf("\n%s\t\t%c\t\t%lld\t\t%lld", customer.customerName, customer.gender, customer.phoneNo, customer.accountNo);
	}
	
	fclose(fptr);
	printf("\nFile is closed.");
}