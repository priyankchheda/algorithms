/**
 * Total number of divisors for a given number
 * Given a positive integer n, we have to find the total number of divisors
 * for n.
 *
 * Examples:
 *
 * Input : n = 25
 * Output : 3
 * Divisors are 1, 5 and 25.
 *
 * Input : n = 24
 * Output : 8
 * Divisors are 1, 2, 3, 4, 6, 8, 12 and 24.
 *
 * URL: https://www.geeksforgeeks.org/total-number-divisors-given-number/
 *
 */

#include <iostream>

#define MAX 1000

int numberOfDivisors(int n)
{
    // sieve of eratosthenes
    std::bitset<MAX+1> primes;
    primes.set();
    for (int p = 2; p * p <= MAX; p++) {
        if (primes[p])
            for (int i = p * p; i <= MAX; i += p)
                primes.reset(i);
    }

    // traversing through all prime numbers
    int total = 1;
    for (int p = 2; p <= MAX && n > 1; p++) {
        if (primes[p]) {
            // calculate number of divisor with formula
            // total divisor is (p1+1) * (p2+1) *.....* (pn+1)
            // where n = (a1 ^ p1) * (a2 ^ p2) .... * (an ^ pn)
            // ai being prime divisor for n and pi are their respective
            // power in factorization
            int count = 0;
            while (n % p == 0) {
                n = n / p;
                count++;
            }
            total *= count + 1;
        }
    }
    return total;
}

int main()
{
    int n = 48;
    std::cout << numberOfDivisors(n) << std::endl;
    return 0;
}