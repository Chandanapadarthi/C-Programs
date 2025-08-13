// Create a linked list to read items records from a file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// #include "removenewline.c"
#define MAX_LEN 50
#define DATA_FILE "itemDList.dat"

struct record
{
    char itemID[MAX_LEN];
    char name[MAX_LEN];
    char price[MAX_LEN];
    char status[MAX_LEN];
};

struct node {
    struct record item;
    struct node *next;
};

struct node *head, *curr, *newNode;
int recordCount;

FILE* validateFile(char fileName[])
{
    FILE *fpItem = fopen(fileName, "rb+");
    if (fpItem == NULL) {
        printf("File couldn't be opened!\n");
        return NULL;
    }
    return fpItem;
}

void removeNewLine(char *string)
{
    int length = strlen(string);
    if (length > 0 && string[length - 1] == '\n') {
        string[length - 1] = '\0';
    }
}

int loadlist(struct node **head) {
    *head = NULL, curr = NULL;
    FILE *fpItem = validateFile(DATA_FILE);
    if (fpItem == NULL) {
        return 0;
    }

    struct record item;
    while (fread(&item, sizeof(struct record), 1, fpItem)) {
        newNode = (struct node*) malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("\nMemory can't be allocated!");
            return recordCount;
        }

        newNode -> item = item;
        newNode -> next = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            curr -> next = newNode;
        }
        curr = newNode;
        recordCount++;

    }
    fclose(fpItem);
    return recordCount;
}

int saveList()
{
    curr = head;
    FILE *fpItem = fopen(DATA_FILE, "wb");
    if (fpItem == NULL) {
        printf("\nCouldn't open the file!\n");
        return -1;
    }
    // rewind(fpItem);
    while (curr != NULL) {
        fwrite(&curr -> item, sizeof(struct record), 1, fpItem);
        curr = curr -> next;
    }
    fclose(fpItem);
}

int insertNode()
{
    curr = head;
    newNode = (struct node*) malloc (sizeof(struct node));
    if (head != NULL) {
        while (curr -> next != NULL) {
            curr = curr -> next;
        }
        curr -> next = newNode;
    }
    else {
        head = newNode;
    }
    printf("Enter the ID: ");
    scanf("%s", newNode -> item.itemID);
    fflush(stdin);
    printf("Enter the name: ");
    fgets(newNode -> item.name, sizeof(newNode -> item.name), stdin);
    removeNewLine(newNode -> item.name);
    printf("Enter the price: ");
    scanf("%s", newNode -> item.price);
    strcpy(newNode -> item.status, "U");
    curr = newNode;
    curr -> next = NULL;
    saveList();
    printf("\nInserted successfully!\n");
}

int showList() 
{
    curr = head;
    int itemCounter = 0;
    printf("\n---------------Items List---------------\n");
    while (curr != NULL) {
        printf("\n----------Item-%d-----------\n", ++itemCounter);
        printf("ID: %s\nName: %s\nPrice: %s\n", curr -> item.itemID, curr -> item.name, curr -> item.price);
        curr = curr -> next;
    }
    printf("\nAll items are retrieved!\n");
    return 1;
}

int updateList()
{
    curr = head;
    char id[MAX_LEN];
    printf("Enter the item ID: ");
    scanf("%s", id);
    while (curr != NULL) {
        if (strcmp(curr -> item.itemID, id) == 0) {
            while (1) {
                int choice;
                printf("1. Update item ID\n2. Update item name\n3. Update price\n4. No more updates\nEnter your choice: ");
                scanf("%d", &choice);
                fflush(stdin);
                switch (choice) {
                    case 1: printf("\nEnter the updated ID: ");
                            scanf("%s", curr -> item.itemID);
                            break;
                    case 2: printf("\nEnter the updated name: ");
                            fgets(curr -> item.name, sizeof(curr -> item.name), stdin);
                            removeNewLine(curr -> item.name);
                            break;
                    case 3: printf("\nEnter the updated amount: ");
                            scanf("%s", curr -> item.price);
                            break;
                    case 4: printf("\nChanges are seccessfull!\n");
                            break;
                    default: printf("\nEnter a valid choice!\n");
                            break;
                }
                if (choice == 4) {
                    break;
                }
            }
            saveList();
            break;
        }
        curr = curr -> next;
    }
    if (curr == NULL) {
        printf("\nEnter a valid ID!\n");
        return 0;
    }
    return 1;
}

int deleteNode()
{
    curr = head;
    struct node *prev = head;
    char id[MAX_LEN];
    printf("\nEnter the ID: ");
    scanf("%s", id);
    while (curr != NULL) {
        if (strcmp(curr -> item.itemID, id) == 0 ) {
            if (curr == head) {
                head = curr -> next;
                curr = curr -> next;
                break;
            }
            prev -> next = curr -> next;
            break;
        }
        prev = curr;
        curr = curr -> next;
    }
    if (curr == NULL) {
        printf("\nEnter a valid ID!\n");
        return 0;
    }
    free(curr);
    saveList();
    printf("\nDeleted Successfully!\n");
}

void searchNode()
{
    char id[MAX_LEN];
    printf("Enter the ID: ");
    scanf("%s", id);
    curr = head;
    while (curr != NULL) {
        if (strcmp(curr -> item.itemID, id) == 0) {
            printf("Item ID: %s\nName: %s\nPrice: %s\n", curr -> item.itemID, curr -> item.name, curr -> item.price);
            break;
        }
        curr = curr -> next;
    }
    if (curr == NULL) {
        printf("\nEnter a valid ID!\n");
    }
}

void swapItems(struct record *item1, struct record *item2) {
    struct record temp = *item1;
    *item1 = *item2;
    *item2 = temp;
}

void sortList() {
    if (head == NULL) return;

    int choice;
    printf("\n1. Sort by ID\n2. Sort by names (alphabetical order)\n3. Sort by price\nEnter your choice: ");
    scanf("%d", &choice);

    bool swapped = true;
    struct node *last = NULL;

    while (swapped) {
        swapped = false;
        curr = head;

        while (curr->next != last) {
            bool sorted = false;

            if (choice == 1) {
                sorted = strcmp(curr->item.itemID, curr->next->item.itemID) > 0;
            } 
            else if (choice == 2) {
                sorted = strcmp(curr->item.name, curr->next->item.name) > 0;
            } 
            else if (choice == 3) {
                sorted = atof(curr->item.price) > atof(curr->next->item.price);
            }

            if (sorted) {
                swapItems(&curr->item, &curr->next->item);
                swapped = true;
            }

            curr = curr->next;
        }
        last = curr;
    }
    
    showList();
    printf("\nList sorted successfully.\n");
}
// {
//     struct node *curr = head, *prev = head, *prevBefore = head;
//     int choice;
//     printf("\n1. Sort by ID\n2. Sort by names(alphabetical order)\n3. Sort by price\nEnter your choice: ");
//     scanf("%d", &choice);
//     bool sorted = false;
//     if (choice == 1) {
//         while (curr != NULL && sorted == false) {
//             sorted = true;
//             if(strcmp(curr -> item.itemID, prev -> item.itemID) > 0) {
//                 prevBefore -> next = curr;
//                 prev -> next = curr -> next;
//                 curr -> next = prev;
//                 sorted = false;
//             }
//             if (curr == NULL && sorted == false) {
//                 curr = head;
//                 sorted = false;
//             }
//             prevBefore = prev;
//             prev = curr;
//             curr = curr -> next;
//             showList(head);
//         }
//     }
// }
    


int main() {
    recordCount = loadlist(&head);
    printf("Total records loaded: %d\nHead: %u", recordCount, head);
    while (1) {
        int choice;
        printf("\n1. Create node\n2. Retrieve list\n3. Update list\n4. Delete node\n5. Search node\n6. Sort the list\n7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: insertNode();
                    break;
            case 2: showList();
                    break;
            case 3: updateList();
                    break;
            case 4: deleteNode();
                    break;
            case 5: searchNode();
                    break;
            case 6: sortList();
                    break;
            case 7: printf("\nYou have exited the program!");
                    return 0;
            default: printf("\nEnter a valid choice!\n");
                     break;
        }
    }
    return 0;
}