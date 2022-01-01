/**
 * Find the element that appears once in an array where every other element
 * appears twice
 *
 * Given an array of integers. All numbers occur twice except one number which
 * occurs once. Find the number in O(n) and constant extra space.
 *
 * Input: a[] = {7, 3, 5, 4, 5, 3, 4}
 * Output: 7
 *
 * Solution:
 * The best solution is to use XOR. XOR of all array elements gives us the
 * number with a single occurrence. The idea is based on the following two
 * facts.
 * a) XOR of a number with itself is 0.
 * b) XOR of a number with 0 is number itself.
 *
 * Let us consider the above example.
 * Let ^ be xor operator as in C and C++.
 *
 * res = 7 ^ 3 ^ 5 ^ 4 ^ 5 ^ 3 ^ 4
 *
 * Since XOR is associative and commutative, above
 * expression can be written as:
 * res = 7 ^ (3 ^ 3) ^ (4 ^ 4) ^ (5 ^ 5)
 *     = 7 ^ 0 ^ 0 ^ 0
 *     = 7 ^ 0
 *     = 7
 */

#include <iostream>


int findSingle(int arr[], int size)
{
    int result = arr[0];
    for (int i = 1; i < size; i++)
        result = result ^ arr[i];
    return result;
}

int main()
{
    int arr[] = {7, 3, 5, 4, 5, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << "element occuring once is " << findSingle(arr, n) << "\n";
    return 0;
}
