// Print the details of the given item using curl

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char command[100] = "";
    char url[100] = "http://138.68.140.83:8080/Chandana/testmysql.jsp?itemID=";
    char itemID[10];
    printf("Enter the item ID: ");
    scanf("%s", itemID);
    sprintf(command, "curl %s%s", url, itemID);
    system(command);
}