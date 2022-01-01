/**
 * Modular Multiplicative Inverse
 *
 * Given two integers ‘a’ and ‘m’, find modular multiplicative inverse of ‘a’
 * under modulo ‘m’. The modular multiplicative inverse is an integer ‘x’
 * such that.
 *
 * a x ≅ 1 (mod m)
 *
 * The value of x should be in {0, 1, 2, … m-1}, i.e., in the range of
 * integer modulo m. The multiplicative inverse of “a modulo m” exists
 * if and only if a and m are relatively prime (i.e., if gcd(a, m) = 1).
 *
 * Examples:
 *
 * Input:  a = 3, m = 11
 * Output: 4
 * Since (4*3) mod 11 = 1, 4 is modulo inverse of 3(under 11).
 * One might think, 15 also as a valid output as "(15*3) mod 11"
 * is also 1, but 15 is not in ring {0, 1, 2, ... 10}, so not
 * valid.
 *
 * Input:  a = 10, m = 17
 * Output: 12
 * Since (10*12) mod 17 = 1, 12 is modulo inverse of 10(under 17).
 *
 */

#include <iostream>
#include <tuple>
using namespace std;

// extended euclidean algorithm
tuple<int, int, int> extended_gcd(int a, int b)
{
	if (a == 0)
		return make_tuple(b, 0, 1);

	int gcd, x, y;

	// unpack tuple  returned by function into variables
	tie(gcd, x, y) = extended_gcd(b % a, a);

	return make_tuple(gcd, (y - (b/a) * x), x);
}

void modular_multiplicative_inverse(int a, int m)
{
	tuple<int, int, int> t = extended_gcd(a, m);

	int gcd = get<0>(t);
	int x = get<1>(t);

    if (gcd != 1)
        cout << "Inverse doesn't exist\n";
    else {
        // m is added to handle negative x
        int result = (x % m + m) % m;
        cout << "modular multiplicative inverse is " << result << "\n";
    }
}

int main()
{
    modular_multiplicative_inverse(3, 11);
    return 0;
}
