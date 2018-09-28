#!/usr/bin/env python2

import sys
import numpy

def sieve(n):
    is_prime = numpy.zeros(n+1)
    is_prime[0] = is_prime[1] = 1;
    number_of_primes = 0
    for i in xrange(n):
        if is_prime[i] == 0:
            number_of_primes += 1
            for j in xrange(2*i, n+1, i):
                is_prime[j] = 1
    return number_of_primes

n = int(sys.argv[1])
print("Number of primes: %d" % sieve(n))
