/**
 * GCD(HCF) of two numbers (Euclidean Algorithm)
 * GCD (Greatest Common Divisor) or HCF (Highest Common Factor) of two numbers
 * is the largest number that divides both of them.
 *
 * Explanation:
 * 36 = 2 x 2 x 3 x 3
 * 60 = 2 x 2 x 3 x 5
 * GCD = 2 x 2 x 3 = 12
 *
 * The time complexity for the above algorithm is O(log(min(a,b))).
 *
 */

#include <iostream>

// recursive function to return gcd of a and b
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a = 98, b = 56;
    std::cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << "\n";
    return 0;
}
