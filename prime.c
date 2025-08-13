// Print whether the given number is prime or not.

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void main() {
	int number;
	printf("Enter a number to check if it's prime or not: ");
	scanf("%d", &number);
	bool isPrime = true;
	if(number < 2) {
		isPrime = false;
	} else if(number == 2 || number == 3) {
		isPrime = true;
	} else if(number % 2 == 0) {
		isPrime = false;
	} else if(number > 3) {
		int sqroot = sqrt(number);
		for(int i = 3; i <= sqrt(number); i+=2) {
			if(number % i == 0) {
				isPrime = false;
				break;
			}			
		}
	}
	
	if(isPrime) {
		printf("%d is prime.", number);
	} else {
		printf("%d is not prime.", number);
	}
}