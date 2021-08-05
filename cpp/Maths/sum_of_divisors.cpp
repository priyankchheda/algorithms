/**
 * Sum of all proper divisors of a natural number
 *
 * Given a natural number, calculate sum of all its proper divisors. A proper
 * divisor of a natural number is the divisor that is strictly less than
 * the number.
 *
 * For example, number 20 has 5 proper divisors: 1, 2, 4, 5, 10, and the
 * divisor summation is: 1 + 2 + 4 + 5 + 10 = 22.
 *
 * Example:
 * Input : num = 10
 * Output: 8
 * // proper divisors 1 + 2 + 5 = 8
 *
 * Input : num = 36
 * Output: 55
 * // proper divisors 1 + 2 + 3 + 4 + 6 + 9 + 12 + 18 = 55
 *
 * URL:https://www.geeksforgeeks.org/sum-of-all-proper-divisors-of-a-natural-number/
 *
 */

#include <iostream>

#define MAX 1000

int sumOfDivisors(int n)
{
    // sieve of erathothenes
    std::bitset<MAX+1> prime;
    prime.set();
    for (int p = 2; p * p <= MAX; p++)
        if (prime[p])
            for (int i = p * p; i <= MAX; i += p)
                prime.reset(i);

    int total = 1;
    for (int p = 2; p <= MAX; p++) {
        if (prime[p]) {
            int res = 1;
            int count = 1;
            while (n % p == 0) {
                n = n / p;
                count *= p;
                res += count;
            }
            total *= res;
        }
    }
    return total;
}

int main()
{
    int sum = sumOfDivisors(2400);
    std::cout << sum << std::endl; // Output: 7812
    return 0;
}