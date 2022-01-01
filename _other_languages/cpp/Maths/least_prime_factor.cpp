/**
 * Least Prime Factor of numbers till n
 *
 * Given a number n, print least prime factors of all numbers from 1 to n.
 * The least prime factor of an integer n is the smallest prime number that
 * divides the number. The least prime factor of all even numbers is 2. A prime
 * number is its own least prime factor (as well as its own greatest prime
 * factor).
 *
 * Note: We need to print 1 for 1.
 * Example :
 *
 * Input : 6
 * Output : Least Prime factor of 1: 1
 *          Least Prime factor of 2: 2
 *          Least Prime factor of 3: 3
 *          Least Prime factor of 4: 2
 *          Least Prime factor of 5: 5
 *          Least Prime factor of 6: 2
 */

#include <iostream>

void leastPrimeFactors(int n)
{
    int leastPrime[n+1];
    memset(leastPrime, 0, sizeof(leastPrime));

    leastPrime[1] = 1;

    for (int i = 2; i <= n; i++) {
        // if i is prime
        if (leastPrime[i] == 0)
            leastPrime[i] = i;

        // mark it as a divisor for all its multiples if not already marked
        for (int j = i*i; j <= n; j += i) {
            if (leastPrime[j] == 0)
                leastPrime[j] = i;
        }
    }

    // print least prime factor of numbers till n
    for (int i = 2; i <= n; i++)
        std::cout << "Least Prime factor of " << i << ": "
            << leastPrime[i] << std::endl;
}

int main()
{
    int n = 20;
    leastPrimeFactors(n);
    return 0;
}