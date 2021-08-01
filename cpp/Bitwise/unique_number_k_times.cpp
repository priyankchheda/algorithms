/**
 * Unique element in an array where all elements occur k times except one
 *
 * Given an array which contains all elements occurring k times, but one
 * occurs only once. Find that unique element.
 * Input: arr[] = {6, 2, 5, 2, 2, 6, 6} k = 3
 * Output: 5
 * Explanation: Every element appears 3 times accept 5.
 *
 * URL: https://www.geeksforgeeks.org/find-unique-element-element-occurs-k-
 *      times-except-one/
 */

#include <iostream>
#include <vector>

int find_unique(int arr[], int n, int k)
{
    std::vector<int> counter(8 * sizeof(int), 0);

    // store all bit information of all numbers in counter array
    for (int i = 0; i < n; i++) {
        int j = 0;
        int num = arr[i];
        while (num > 0) {
            if (num & 1)
                counter[j]++;
            num = num >> 1;
            j++;
        }
    }

    // take modulo k of all elements in counter
    // remaining bits represents binary value of result
    int result = 0;
    for (int i = 0; i < counter.size(); i++) {
        counter[i] %= k;
        result += counter[i] * (1 << i);
    }

    return result;
}

int main()
{
    int arr[] = {6, 6, 2, 5, 2, 5, 2, 2, 6, 6, 5, 5, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    std::cout << find_unique(arr, n, k) << "\n";

    return 0;
}
