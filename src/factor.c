/*
	Find the prime factorization of a number.
	Command line utility.
	Josh Barney
	joshuareedbarney@gmail.com
	January 15th 2020
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	if (argc < 2) {
		//
		return 0;
	}

	int n = atoi(argv[1]);
	printf(argv[1]);
	printf("\n");
	printf("%d", n);
	
	return 0;
}

