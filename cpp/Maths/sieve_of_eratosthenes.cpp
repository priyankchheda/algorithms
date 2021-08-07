/**
 * Sieve of Eratosthenes
 *
 * Given a number n, print all primes smaller than or equal to n. It is also
 * given that n is a small number.
 *
 * Example:
 *
 * Input : n = 10
 * Output : 2 3 5 7
 *
 * Input : n = 20
 * Output: 2 3 5 7 11 13 17 19
 *
 * URL: https://www.geeksforgeeks.org/sieve-of-eratosthenes
 */

#include <iostream>
#include <bitset>
#define MAX 31

void sieve_of_eratosthenes(int n)
{
    // create a bitset prime[0..n] and set all entires to 1. A value at
    // prime[i] will finally be false(0) if i is not prime, else true(1).
    std::bitset<MAX> prime;
    prime.set();
    for (int p = 2; p * p <= n; p++) {
        // if prime[p] is not changed, then it is a prime.
        if (prime[p]) {
            // update all multiples of p greater than or equal to the
            // square of it numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime.reset(i);
        }
    }

    // print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            std::cout << p << " ";
}


int main()
{
    int n = 30;
    std::cout << "Prime Numbers less than or equal to N:\n";
    sieve_of_eratosthenes(n);
    std::cout << std::endl;
    return 0;
}
