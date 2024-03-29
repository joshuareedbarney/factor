/*
	Find the prime factorization of a number.
	Command line utility.
	Josh Barney
	joshuareedbarney@gmail.com
	January 15th 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int ARRAY_SIZE = 1000;

void factor(unsigned long long n, unsigned long long* arr) {
	if (n <= 0) {
		return;
	}

	int index = 0;
	unsigned long long sqrtOfN = sqrt(n) + 1;
	
	while (n != 1)
	{
		unsigned long long i = 2;
		while (n % i != 0) {
			i++;
			if (i > sqrtOfN) {
				arr[index++] = n;
				arr[index++] = -1;
				return;
			}
		}
		if (index + 2 >= ARRAY_SIZE) {
			printf("Prime factorization has exceeded maximum array size: %d\n", ARRAY_SIZE);
			exit(1);
		}
		arr[index++] = i;
		n /= i;
		sqrtOfN = sqrt(n) + 1;
	}
	arr[index++] = -1;
}

int main(int argc, char * argv[]) {
	if (argc < 2) {
		printf("Please provide a number to factor\n");
		return 0;
	}

	unsigned long long n = strtoull(argv[1], NULL, 10);
	unsigned long long arr[ARRAY_SIZE];

	if (n == -1 || n <= 0) {
		printf("%llu: \n", n);
		return 0;
	}

	/* if (n == 1) {
		printf("1: 1\n");
		return 0;
	} */

	//-1 is the flag signaling the end of factors
	arr[0] = -1;

	factor(n, arr);

	int index = 0;
	printf("%llu:", n);

	while (index <= ARRAY_SIZE && arr[index] != -1)
	{
		printf(" %llu", arr[index]);
		index++;
	}
	
	printf("\n");

	return 0;
}

