#include <stdio.h>
#include <stdlib.h>

#define	TRUE	0
#define	FALSE	1

long sieve(long n)
{
	long number_of_primes = 0;
	char *is_prime = calloc(n-1, sizeof(char));	// initialized to all TRUE

	for (long i=2; i<=n; ++i) {
		if (is_prime[i-2] == TRUE) {
			number_of_primes++;
//			printf("%ld\n", i);
			for (long j=2*i; j <= n; j+=i) {
				is_prime[j-2] = FALSE;
			}
		}
	}
	free(is_prime);

	return number_of_primes;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Error: No argument.\n");
		return 1;
	}

	long n = atol(argv[1]);
	printf("%ld\n", sieve(n));

	return 0;
}
