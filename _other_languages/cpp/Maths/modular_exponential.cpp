/**
 * Modular Exponentiation (Power in Modular Arithmetic)
 * Given three large numbers x, y and p, compute (xy) % p.
 *
 * Example:
 * Input:  x = 2, y = 3, p = 5
 * Output: 3
 * Explanation: 2^3 % 5 = 8 % 5 = 3.
 *
 * Input:  x = 2, y = 5, p = 13
 * Output: 6
 * Explanation: 2^5 % 13 = 32 % 13 = 6.
 */

#include <iostream>
typedef long long ll;

/*
 * Modular Exponentiation (recursive version)
 * time complexity = O(log b)
 * space complexity = O(log b)
 */
ll mod_power_recursive(ll a, ll b, ll c)
{
    if (b == 0) return 1;
    ll temp = mod_power_recursive(a, b/2, c);

    if (b % 2 == 0) {
        return ((temp % c) * (temp % c)) % c;
    } else {
        return ((a % c) * (temp % c) * (temp % c)) % c;
    }
}


/*
 * Modular Exponentiation (iterative version)
 * time complexity = O(log b)
 * space complexity = O(1)
 */
ll mod_power_iterative(ll a, ll b, ll c)
{
    ll result = 1;
    while (b != 0) {
        if (b % 2 != 0) {
            result = ((result % c) * (a % c)) % c;
        }
        a = ((a % c) * (a % c)) % c;
        b = b / 2;
    }
    return result;
}

int main()
{
    std::cout << mod_power_recursive(13, 7, 7) << std::endl;
    std::cout << mod_power_iterative(13, 7, 7) << std::endl;
}
