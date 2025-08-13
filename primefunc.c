// Print whether the given number is prime by using a function

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int number) {
	if(number < 2) return false;
	else if(number == 2 || number == 3) return true;
	else if(number % 2 == 0) return false;
	else{
		int sqroot = sqrt(number);
		for(int numberCounter = 3; numberCounter < sqroot; numberCounter+=2) {
			if(number % numberCounter == 0) {
				return false;
			}
		}
	}
	return true;
}

int main(void) {
	int inputNumber;
	printf("Enter a number to check if it is prime: ");
	scanf("%d", &inputNumber);
	bool prime = isPrime(inputNumber);
	if(prime) {
		printf("%d is prime.", inputNumber);
	} else {
		printf("%d is not prime.", inputNumber);
	}
}