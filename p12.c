
/*
 * The sequence of triangle numbers is generated by adding the natural numbers. 
 * So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

 * Let us list the factors of the first seven triangle numbers:

 * 1: 1
 * 3: 1,3
 * 6: 1,2,3,6
 * 10: 1,2,5,10
 * 15: 1,3,5,15
 * 21: 1,3,7,21
 * 28: 1,2,4,7,14,28

 * We can see that 28 is the first triangle number to have over five divisors.

 * What is the value of the first triangle number to have over five hundred divisors?
 
 */

#include <stdio.h>
#include <math.h>

int isPrime(long x) {
	long i;
	
	if(x < 8 && (x == 2 || x == 3 || x == 5 || x == 7))
		return 1;
	
	if(x % 2 == 0)
		return 0;
	
	for(i = 2; i < x/2; i++) {
		if(x % i == 0) {
			return 0;
		}
	}
	

	return 1;
}

int numFactors(long x) {
	int i, numFact = 1;
	
	// Possibly create problems for small numbers. 
	// Looked over since we are only interested in large numbers
	int sqrtX = sqrt(x);
	int primes[sqrtX];
	
	if(x == 0 || x == 1)
		return 1;
	
	if(isPrime(x))
		return 1;
	
	// Initialize an array of 0 - x/2 to 0
	for(i = 0; i < sqrtX; i++)
		primes[i] = 0;
	
	
	
	// Checks for case 2 seperately so the primary loop can only be odd numbers
	while(x % 2 == 0) {
		if(x == 0) {
			break;
		}
		primes[2]++;
		x /= 2;
	}

	for(i = 3; i*i < x ; i += 2) {
		if(x % i == 0 && isPrime(i)) {
			primes[i]++;
			x = x/i;
			i -= 2;
			
			if(x == 1)
				break;
			
			if(isPrime(x)) {
				numFact *= 2;
				break;
			}
		}
	}

	for(i = 1; i < sqrtX; i++) 
		if(primes[i] != 0) {
			numFact *= (primes[i] + 1);
		}
		
	return numFact;
}

int main() {
	
	int scale = 2;
	long i, j;
	
	for(i = 1, j = 1; ; j++, i += j) {
		scale = numFactors(i);
		//printf("%ld->%d\n", i, scale); 
		if(scale > 500)
			break;
	}
	
	printf("%ld\n", i);
	
	return 0;
}
