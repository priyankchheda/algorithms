/**
 * Print all prime factors of a given number
 *
 * Given a number n, write an efficient function to print all prime factors
 * of n. For example, if the input number is 12, then output should be “2 2 3”.
 * And if the input number is 315, then output should be “3 3 5 7”.
 *
 * Link: https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
 *
 */

#include <iostream>

void primeFactors(int n)
{
    // while n is divisible by 2, print 2 and divide n by 2.
    while (n % 2 == 0) {
        std::cout << "2 ";
        n = n / 2;
    }

    // after dividing by 2, n must be odd
    // start a loop from i = 3 to square root of n. While i divides n,
    // print i and divide n by i. After i fails to divide n,
    // increment i by 2 and continue.
    for (int i = 3; i * i <= n; i = i + 2) {
        while(n % i == 0) {
            std::cout << i << " ";
            n = n / i;
        }
    }

    // if resultant n is a prime number and is greater than 2, then n will
    // not become 1 by above two steps. So print n if it is greater than 2.
    if (n > 2)
        std::cout << n;

    std::cout << std::endl;
}

int main()
{
    int n = 315;
    primeFactors(n);
    return 0;
}