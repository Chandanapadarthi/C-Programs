// Item List

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LEN 20

struct itemDetails;
int addnewItem(char*, struct itemDetails);
int updateItemList(char*, struct itemDetails);
int showAllItems(char*, struct itemDetails);
int removeItem(char*, struct itemDetails);

struct itemDetails
{
    char itemID[MAX_LEN];
    char itemName[MAX_LEN];
    float price;
    char itemStatus;
};

int addNewItem(char *fileName, struct itemDetails item)
{
    printf("Enter the item ID: ");
    scanf("%s", item.itemID);
    fflush(stdin);
    printf("Enter the item name: ");
    fgets(item.itemName, sizeof(item.itemName), stdin);
    item.itemName[strlen(item.itemName) - 1] = '\0';
    printf("Enter the price of the item: ");
    scanf("%f", &item.price);
    item.itemStatus = 'U';
    FILE *fpItem = fopen(fileName, "ab+");
    if (fpItem == NULL) {
        printf("\nFile couldn't be opened!");
        return -1;
    }

    fwrite(&item, sizeof(item), 1, fpItem);
    fclose(fpItem);
    printf("\nItem is successfully added to the list.\n");
}

int updateItemDetails(char *fileName, struct itemDetails item)
{
    char itemId[MAX_LEN];
    printf("\nEnter the item ID: ");
    scanf("%s", itemId);
    FILE *fpItem = fopen(fileName, "rb+");
    if (fpItem == NULL) {
        printf("\nFile couldn't be opened.\n");
        return -1;
    }
    bool found = false;
    while (fread(&item, sizeof(item), 1, fpItem)) {
        if(!strcmp(item.itemID, itemId)) {
            found = true;
            break;
        }
    }
    if (!found) {
        printf("\nEnter a valid item ID!");
        return -1;
    }
    int choice;
    while (1) {
        printf("\n1. Update the item ID\n2. Change the item name\n3. Update the price of the item\n4. No more updates\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("\nEnter the new ID: ");
                    scanf("%s", item.itemID);
                    break;
            case 2: fflush(stdin);
                    printf("\nEnter the new name of the item: ");
                    fgets(item.itemName, sizeof(item.itemName), stdin);
                    item.itemName[strlen(item.itemName) - 1] ='\0';
                    break;
            case 3: printf("\nEnter the updates price of the item: ");
                    scanf("%f", &item.price);
                    break;
            case 4: fseek(fpItem, -(long) (sizeof(item)), SEEK_CUR);
                    fwrite(&item, sizeof(item), 1, fpItem);
                    fclose(fpItem);
                    printf("\nItem details are successfully updated!\n");
                    return 0;
            default: printf("\nEnter a valid chocie!\n");
                    break;
        }
    }
}

int showAllItems(char *fileName, struct itemDetails item)
{
    FILE *fpItem = fopen(fileName, "rb+");
    if (fpItem == NULL) {
        printf("\nFile couldn't be opened!\n");
        return -1;
    }
    printf("\n%*s%*s%*s%*s", MAX_LEN, "Item ID", MAX_LEN, "Item Name", MAX_LEN, "Price", MAX_LEN, "Status");
    while (fread(&item, sizeof(item), 1, fpItem)) {
        printf("\n%*s%*s%*.2f%*c", MAX_LEN, item.itemID, MAX_LEN, item.itemName, MAX_LEN, item.price, MAX_LEN, item.itemStatus);
    }

    fclose(fpItem);
    printf("\nAll items are retrieved successfully!\n");
}

int removeItem(char *fileName, struct itemDetails item) 
{
    char itemId[MAX_LEN];
    printf("\nEnter the item ID which is to be removed: ");
    scanf("%s", itemId);

    FILE *fpItem = fopen(fileName, "rb+");
    if (fpItem == NULL) {
        printf("\nFile couldn't be opened!\n");
        return -1;
    }
    bool found = false;
    while (fread(&item, sizeof(item), 1, fpItem)) {
        if(!strcmp(item.itemID, itemId)) {
            found = true;
            break;
        }
    }
    if(!found) {
        printf("\nEnter a valid item ID!\n");
        return -1;
    }

    item.itemStatus = 'R';
    fseek(fpItem, -(long) (sizeof(item)), SEEK_CUR);
    fwrite(&item, sizeof(item), 1, fpItem);
    fclose(fpItem);
    printf("\nItem is successfully removed from the list!\n");
}

int main()
{
    int choice;
    char fileName[] = "ItemDList.dat";
    struct itemDetails item;
    printf("\n\tLocal store's Item List\n");
    while (1) {
        printf("\n1. Add new item\n2. Update item details\n3. Retrieve all items details\n4. Remove the item\n5. Exit the list\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addNewItem(fileName, item);
                    break;
            case 2: updateItemDetails(fileName, item);
                    break;
            case 3: showAllItems(fileName, item);
                    break;
            case 4: removeItem(fileName, item);
                    break;
            case 5: printf("\nYou have closed the list.");
                    return 0;
            default: printf("\nEnter a valid choice!");
                    break;
        }
    }
}