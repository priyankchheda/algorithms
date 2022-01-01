/**
 * Count Divisors of Factorial
 * Given a number n, count total number of divisors of n!.
 *
 * Explanation:
 * Input : n = 4
 * Output: 24
 * 4! is 24. Divisors of 24 are 1, 2, 3, 4, 6, 8, 12 and 24.
 *
 * Input : n = 5
 * Output : 16
 * 5! is 120. Divisors of 120 are 1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 20, 24, 30,
 * 40, 60 and 120
 *
 * Input : n = 6
 * Output : 30
 *
 * URL: https://www.geeksforgeeks.org/count-divisors-of-factorial/
 *
 */

#include <iostream>
#include <vector>

#define MAX 1000000

// sieve of eratosthenes
void sieve(std::vector<int> &primes, int n)
{
    std::bitset<MAX> prime;
    prime.set();
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime.reset(i);
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
}

int factorialDivisors(int n)
{
    std::vector<int> primes;
    sieve(primes, n); // create sieve

    // find exponents of all primes which divides n and less than n
    int result = 1;
    for (int i = 0; i < primes.size(); i++) {
        int p = primes[i];

        // Find the highest power (stored in exp)
        // of allPrimes[i] that divides n using Legendre's formula.
        int exp = 0;
        while (p <= n) {
            exp = exp + (n/p);
            p = p * primes[i];
        }
        // Multiply exponents of all primes less than n
        result = result * (exp + 1);
    }
    return result;
}

int main()
{
    std::cout << factorialDivisors(6) << "\n";
    return 0;
}
