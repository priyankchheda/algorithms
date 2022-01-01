/**
 * Count number of common elements between two arrays by using bitset and
 * Bitwise operation
 *
 * Given two arrays a[] and b[], the task is to find the count of common
 * elements in both the given arrays. Note that both the arrays contain
 * distinct (individually) positive integers.
 *
 * Input: a[] = {1, 2, 3}, b[] = {2, 4, 3}
 * Output: 2
 * Explanation: 2 and 3 are common to both the arrays.
 */

#include <iostream>

#define MAX 1000

int count_common(int arr[], int n, int brr[], int m)
{
	std::bitset<MAX> a, b;
    for (int i = 0; i < n; i++)
        a.set(arr[i]);

    for (int i = 0; i < m; i++)
        b.set(brr[i]);

    std::bitset<MAX> result = a & b;
    return result.count();
}

int main()
{
	int a[] = { 1, 4, 7, 2, 3 };
    int b[] = { 2, 11, 7, 4, 15, 20, 24 };
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    std::cout << count_common(a, n, b, m) << "\n"; // 3
    return 0;
}
