/**
 * Legendre’s formula (Given p and n, find the largest x such that p^x
 * divides n!)
 *
 * Given an integer n and a prime number p, find the largest x such that
 * p^x (p raised to power x) divides n! (factorial)
 *
 * Input:  n = 7, p = 3
 * Output: x = 2
 * Explanation: 32 divides 7! and 2 is the largest such power of 3.
 *
 * Input:  n = 10, p = 3
 * Output: x = 4
 * Explanation: 34 divides 10! and 4 is the largest such power of 3.
 *
 * URL: https://www.geeksforgeeks.org/legendres-formula-highest-power-of-
 *      prime-number-that-divides-n/
 *
 */

#include <iostream>

// returns largest power of p that divides n!
int largest_power(int n, int p)
{
    int result = 0;

    // calculate x = n/p + n/(p^2) + n/(p^3) + ....
    while (n) {
        n /= p;
        result += n;
    }
    return result;
}

int main()
{
    int n = 10, p = 3;
    std::cout << "the largest power of " << p <<" that divides " << n <<
        "! is " << largest_power(n, p) << std::endl;
    return 0;
}
