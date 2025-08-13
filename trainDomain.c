// Train Domain

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_PNR_LEN 15
#define MAX_NAME_LEN 40

struct ticketDetails;
int generateTicket(char*, struct ticketDetails);
int updateTicketDetails(char*, struct ticketDetails);
int showAllTicketsDetails(char*, struct ticketDetails);
int cancelTicket(char*, struct ticketDetails);

struct ticketDetails
{
    char PNRNumber[MAX_PNR_LEN];
    char passengerName[MAX_NAME_LEN];
    char boardingPlace[MAX_NAME_LEN];
    char destination[MAX_NAME_LEN];
    float ticketFare;
    char ticketStatus;
};

int generateTicket(char *fileName, struct ticketDetails ticket)
{
    printf("Enter the PNR number of the passenger: ");
    scanf("%s", ticket.PNRNumber);
    fflush(stdin);
    printf("Enter the passenger name: ");
    fgets(ticket.passengerName, sizeof(ticket.passengerName), stdin);
    ticket.passengerName[strlen(ticket.passengerName) - 1] = '\0';
    printf("Enter the boarding station: ");
    scanf("%s", ticket.boardingPlace);
    printf("Enter the destination: ");
    scanf("%s", ticket.destination);
    printf("Enter the total ticket fare: ");
    scanf("%f", &ticket.ticketFare);
    ticket.ticketStatus = 'B';
    FILE *fpTicket = fopen(fileName, "ab+");
    if (fpTicket == NULL) {
        printf("\nFile couldn't be opened.");
        return -1;
    }

    fwrite(&ticket, sizeof(ticket), 1, fpTicket);
    fclose(fpTicket);
    printf("\nNew ticket is generated successfully!\n");
}

int updateTicketDetails(char *fileName, struct ticketDetails ticket)
{
    char pnrNumber[MAX_PNR_LEN];
    printf("Enter the PNR of the passenger: ");
    scanf("%s", pnrNumber);

    FILE *fpTicket = fopen(fileName, "rb+");
    if (fpTicket == NULL) {
        printf("\nFile couldn't be opened!\n");
        return -1;
    }
    bool found = false;
    while (fread(&ticket, sizeof(ticket), 1, fpTicket)) {
        if(!strcmp(ticket.PNRNumber, pnrNumber)) {
            found = true;
            break;
        }
    }
    if(!found) {
        printf("\nEnter a valid PNR number!\n");
        return -1;
    }
    int choice;
    while (1) {
        printf("\n1. Change the PNR number\n2. Change the paseenger's name\n3. Update the boarding place\n4. Update the destination\n5. Update the tickrt fare\n6. No more updates\n");
        printf("\nEnter your chocie: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("\nEnter the new PNR number: ");
                    scanf("%s", ticket.PNRNumber);
                    break;
            case 2: fflush(stdin);
                    printf("\nEnter the updated name of the passenger: ");
                    fgets(ticket.passengerName, sizeof(ticket.passengerName), stdin);
                    ticket.passengerName[strlen(ticket.passengerName) - 1] = '\0';
                    break;
            case 3: printf("\nEnter the updated boarding place: ");
                    scanf("%s", ticket.boardingPlace);
                    break;
            case 4: printf("\nEnter the updated destination: ");
                    scanf("%s", ticket.destination);
                    break;
            case 5: printf("\nEnter the updated ticket fare: ");
                    scanf("%f", &ticket.ticketFare);
                    break;
            case 6: fseek(fpTicket, -(long) (sizeof(struct ticketDetails)), SEEK_CUR);
                    fwrite(&ticket, sizeof(ticket), 1, fpTicket);
                    fclose(fpTicket);
                    printf("\nUpdates are successful!\n");
                    return 0;
            default: printf("\nEnter the correct choice!");
                     break;
        }
    }
}

int showAllTicketsDetails(char *fileName, struct ticketDetails ticket)
{
    FILE *fpTicket = fopen(fileName, "rb");
    if (fpTicket == NULL) {
        printf("\nFile couldn't be opened!");
        return -1;
    }
    int ticketCounter = 1;
    while (fread(&ticket, sizeof(ticket), 1, fpTicket)) {
        printf("\n---------------Ticket-%d Details----------------", ticketCounter++);
        printf("\nPNR Number: %s\nPassenger Name: %s\nFrom: %s\nTo: %s\nTicket Fare: %.2f\nTicket Status: %c\n", ticket.PNRNumber, ticket.passengerName, ticket.boardingPlace, ticket.destination, ticket.ticketFare, ticket.ticketStatus);
    }
    fclose(fpTicket);
    printf("\nAll tickets details are successfully retrieved!\n");
}

int cancelTicket(char *fileName, struct ticketDetails ticket) 
{
    char pnrNumber[MAX_PNR_LEN];
    printf("\nEnter the PNR number of the passenger: ");
    scanf("%s", pnrNumber);
    FILE *fpTicket = fopen(fileName, "rb+");
    if (fpTicket == NULL) {
        printf("\nFile couldn't be opened!");
        return -1;
    }
    bool found = false;
    while (fread(&ticket, sizeof(ticket), 1, fpTicket)) {
        if(!strcmp(ticket.PNRNumber, pnrNumber)) {
            found = true;
            break;
        }
    }

    if(!found) {
        printf("\nEnter a valid PNR number!\n");
        return -1;
    }
    ticket.ticketStatus = 'C';
    fseek(fpTicket, -(long) (sizeof(struct ticketDetails)), SEEK_CUR);
    fwrite(&ticket, sizeof(ticket), 1, fpTicket);
    fclose(fpTicket);
    printf("\nCanceled the ticket succesfully!\n");
}

int main()
{
    int choice;
    char fileName[] = "TicketDetails.dat";
    struct ticketDetails ticket;
    printf("\tWelcome to Railway Database");
    while (1) {
        printf("\n1. Generate a new Ticket\n2. Update tickte details\n3. Retrieve all tickets details\n4. Cancel a ticket\n5. Exit the database\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: generateTicket(fileName, ticket);
                    break;
            case 2: updateTicketDetails(fileName, ticket);
                    break;
            case 3: showAllTicketsDetails(fileName, ticket);
                    break;
            case 4: cancelTicket(fileName, ticket);
                    break;
            case 5: printf("\nYou have exited the database.");
                    return 0;
            default: printf("\nEnter a valid choice!\n");
        }
    }
    return 0;
}