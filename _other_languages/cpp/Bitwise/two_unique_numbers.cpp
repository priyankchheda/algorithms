/**
 * Find the two non-repeating elements in an array of repeating elements.
 * Given an array in which all numbers except two are repeated once. (i.e. we
 * have 2n+2 numbers and n numbers are occurring twice and remaining two have
 * occurred once). Find those two numbers in the most efficient way.
 *
 * URL: https://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-
 *      array-of-repeating-elements/
 */

#include <iostream>
#include <vector>

int two_unique_numbers(int arr[], int n)
{
	// xor all elements in array
    int result;
    for (int i = 0; i < n; i++)
        result ^= arr[i];

	// Check the first bit which is set
    int _result = result;
    int index = 0;
    while (_result > 0) {
        if (_result & 1) break;
        index++;
        _result = _result >> 1;
    }

    // check the elements where index-th bit is set
    int mask = 1 << index;
    std::vector<int> temp_arr;
    for (int i = 0; i < n; i++) {
        if (arr[i] & mask)
            temp_arr.push_back(arr[i]);
    }

    // XOR all element from above step
    int a = 0;
    for (int i = 0; i < temp_arr.size(); i++)
        a ^= temp_arr[i];

    int b = result ^ a;
    std::cout << a << " " << b << "\n";

    return 0;
}

int main()
{
    int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    two_unique_numbers(arr, n);
}
