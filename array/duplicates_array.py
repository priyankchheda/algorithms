"""
Problem:
The problem is that we want to find duplicates in a one-dimensional
array of integers in O(N) running time where the integer values are
smaller than the length of the array!

Solution:
1. brute-force approach (comparing items with all the rest) but it has
   O(N^2) running time complexity
2. hashmap (dict in python): Traverse the given array and try to insert each
   item in a hashtable with the value as the key. If you can not insert the
   item it means it is duplicate
   problem: not an in-place algorithm
3. Absolute values: with this approach we can achieve O(N) running time
   algorithm that is in-place as well

    check the sign of T[abs(T[i])]:
    if it is positive:
        flip the sign T[abs(T[i])] = -T[abs(T[i])]
    else
        the given i item is a repetition
"""

def duplicates(arr):
    for num in arr:
        if arr[abs(num)] >= 0:
            arr[abs(num)] = - arr[abs(num)]
        else:
            print("duplicate entry:", abs(num))


duplicates([1, 3, 4, 5, 5, 3, 4, 2])
