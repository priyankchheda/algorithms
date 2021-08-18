/**
 * Extended Euclidean Algorithm
 * The extended Euclidean algorithm is an extension to the Euclidean
 * algorithm, which computes, besides the greatest common divisor of integers
 * a and b, the coefficients of Bézout’s identity, that is integers x and y
 * such that
 *
 * ax + by = gcd(a, b)
 *
 * Example:
 * gcd(30, 50) = 10
 * Here, x = 2 y = -1 as 30 * 2 + 50 * -1 = 10
 *
 * gcd(2740, 1760) = 20
 * Here, x = 9 y = -14 as 2740 * 9 + 1760 * -14 = 20
 *
 */

#include <iostream>
#include <tuple>		// std::tuple, std::make_tuple, std::tie
using namespace std;

// function for Extended Euclidean algorithm
// returns multiple values using tuple in C++
tuple<int, int, int> extended_gcd(int a, int b)
{
	if (a == 0)
		return make_tuple(b, 0, 1);

	int gcd, x, y;

	// unpack tuple  returned by function into variables
	tie(gcd, x, y) = extended_gcd(b % a, a);

	return make_tuple(gcd, (y - (b/a) * x), x);
}

// main function
int main()
{
	int a = 30;
	int b = 50;

	tuple<int, int, int> t = extended_gcd(a, b);

	int gcd = get<0>(t);
	int x = get<1>(t);
	int y = get<2>(t);

	cout << "GCD is " << gcd << endl;
	cout << "x = " << x << " y = " << y << endl;

	cout << a << "*" << x << " + " << b << "*" << y << " = " << gcd << "\n";

	return 0;
}
