// Read integer values using pointer to pointer

#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN_B 13
#define MAX_LEN_C 15


void main()
{
	int citizenCount, blocksCount;
	printf("Enter the total number of blocks in the community: ");
	scanf("%d", &blocksCount);
	printf("Enter the number of citizens living in each block: ");
	scanf("%d", &citizenCount);
	int **citizensAges = (int **) malloc (blocksCount * sizeof(int *));
	for (int blocksCounter = 0; blocksCounter < blocksCount; blocksCounter++) {
		citizensAges[blocksCounter] = (int *) malloc (citizenCount * sizeof(int));
	}
	for (int blocksCounter = 0; blocksCounter < blocksCount; blocksCounter++) {
		for (int citizenCounter = 0; citizenCounter < citizenCount; citizenCounter++) {
			printf("Enter the age of citizen-%d in block-%d: ", citizenCounter + 1, blocksCounter + 1);
			scanf("%d", &citizensAges[blocksCounter][citizenCounter]);
		}
		printf("\n");
	}
	printf("%*s", MAX_LEN_C, "Blocks");
	for (int citizenCounter = 0; citizenCounter < citizenCount; citizenCounter++) {
		printf("%*s-%d", MAX_LEN_C, "Citizen", citizenCounter + 1);
	}

	for (int blocksCounter = 0; blocksCounter < blocksCount; blocksCounter++) {
		printf("\n%*s-%d", MAX_LEN_B, "Block", blocksCounter + 1);
		for (int citizenCounter = 0; citizenCounter < citizenCount; citizenCounter++) {
			printf("%*d", MAX_LEN_C, citizensAges[blocksCounter][citizenCounter]);
		}
	}
}