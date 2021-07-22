/**
 * Subset sum queries using bitset
 *
 * Given an array arr[] and a number of queries, where in each query we have
 * to check whether a subset whose sum is equal to given number exists in the
 * array or not.
 *
 * Input : arr[] = {1, 2, 3}
 *         query[] = {5, 3, 8}
 * Output : Yes, Yes, No
 * Explanation:
 * There is a subset with sum 5, subset is {2, 3}
 * There is a subset with sum 3, subset is {1, 2}
 * There is no subset with sum 8.
 *
 * URL: https://www.geeksforgeeks.org/subset-sum-queries-using-bitset/
 */

#include <iostream>
#define MAX 1000

int main()
{
    int arr[] = { 3, 1, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);

    int query[] = { 8, 7 };
    int nq = sizeof(query)/sizeof(query[0]);

    std::bitset<MAX> bit;
    bit[0] = 1; // set the 0th bit because subset sum of 0 exists
    for (int i = 0; i < n; i++) {
		// Do OR of following two
        // 1. All previous sums. We keep previous value of bit.
        // 2. arr[i] added to every previous sum. We  move all previous
        // indexes arr[i] ahead.
        bit |= (bit << arr[i]);
    }

    for (int i = 0; i < nq; i++) {
       int res = query[i];
       std::cout << res << " -> ";
       // if res is a subset sum, then res'th bit must be set
       bit[res] ? std::cout << "YES\n" : std::cout << "NO\n";
    }
    return 0;
}
