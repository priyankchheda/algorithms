/**
 * Prime Factorization using Sieve O(log n) for multiple queries
 *
 * To calculate to smallest prime factor for every number we will use the
 * sieve of eratosthenes. In original Sieve, every time we mark a number
 * as not-prime, we store the corresponding smallest prime factor for that
 * number.
 *
 * Now, after we are done with precalculating the smallest prime factor for
 * every number we will divide our number n (whose prime factorziation is to
 * be calculated) by its corresponding smallest prime factor till n becomes 1.
 *
 * URL: https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
 */

#include <iostream>
#include <vector>

#define MAX 10000

// stores smallest prime factor for every number
int spf[MAX+1];

void sieve()
{
    memset(spf, 0, MAX+1);
    spf[1] = 1;

    for (int i = 2; i <= MAX; i++) {
        if (spf[i] == 0)
            spf[i] = i;

        for (int j = i * i; j <= MAX; j += i) {
            if (spf[j] == 0)
                spf[j] = i;
        }
    }
}

std::vector<int> primeFactorsUsingSieve(int n)
{
    std::vector<int> result;
    while (n > 1) {
        result.push_back(spf[n]);
        n = n / spf[n];
    }
    return result;
}

int main()
{
    sieve();
    int n = 1224;
    std::vector<int> result = primeFactorsUsingSieve(n);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;
    return 0;
}