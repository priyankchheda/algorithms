/**
 * Segmented Sieve (Print Primes in a Range)
 *
 * Given a range [low, high], print all primes in this range?
 * For example, if the given range is [10, 20], then output is 11, 13, 17, 19.
 *
 * URL: https://www.geeksforgeeks.org/segmented-sieve-print-primes-in-a-range/
 *
 */

#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1000000

// sieve of eratosthenes
void simple_sieve(std::vector<int> &primes, int n)
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

void primes_in_range(int low, int high)
{
    // compute all primes smaller or equal to square root of high using
    // simple sieve
    int limit = floor(sqrt(high)) + 1;
    std::vector<int> primes;
    simple_sieve(primes, limit);

    std::bitset<MAX> segsieve;
    segsieve.set();
    if (low == 1) low++;

    // use the found primes by simple sieve to find
    // primes in given range
    for (int i = 0; primes[i] * primes[i] <= high; i++) {
        int p = primes[i];
        // find the minimum number in [low..high] that is
        // multiple of primes[i] (divisible by primes[i])
        int j = floor(low/p) * p;
        if (j < low)
            j += p;

        // j is the first multiple of primes[i] in range [low..high]
        for (; j <= high; j += p) {
            if (j != p)
                segsieve[j-low] = 0;
        }
    }
    for (int i = low; i <= high; i++) {
        if (i <= 1) continue;
        if (segsieve[i-low])
            std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    primes_in_range(10, 20);
    return 0;
}
