// Print the series 1, 4, 27,... upto n terms

#include <stdio.h>

void main() {
	int totalTerms;
	printf("Printing the series 1, 4, 27, 256... upto n.\nUpto how many terms do you want to print: ");
	scanf("%d", &totalTerms);
	printf("The series is ");
	for(long termCounter = 1; termCounter <= totalTerms; termCounter++) {
		long long powerCounter = 1;
		for(int counter = 0; counter < termCounter; counter++) {
			powerCounter = powerCounter * termCounter;
		}
		if(termCounter < totalTerms) {
			printf("%lld, ", powerCounter);
		} else {
			printf("%lld.", powerCounter);
		}
	}
}