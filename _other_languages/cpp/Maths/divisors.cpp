/**
 * Find all divisors of a natural number
 *
 * Given a natural number n, print all distinct divisors of it.
 *
 * Examples:
 *      Input : n = 10
 *      Output: 1 2 5 10
 *
 *      Input:  n = 100
 *      Output: 1 2 4 5 10 20 25 50 100
 *
 *      Input:  n = 125
 *      Output: 1 5 25 125
 *
 * URL: https://www.geeksforgeeks.org/find-divisors-natural-number-set-1/
 *      https://www.geeksforgeeks.org/find-all-divisors-of-a-natural-number-set-2/
 *
 */

#include <iostream>

void getDivisors(int n)
{
    for (int i = 1; i * i <= n; i++) { // time complexity: sqrt(n)
        if (n % i == 0) {
            if (n/i == i)
                std::cout << i << " ";
            else std::cout << i << " " << n/i << " ";
        }
    }
}

int main()
{
    int n = 100;
    getDivisors(n);
    return 0;
}