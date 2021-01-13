""" The problem is that we want to reverse a T[] array in O(N) linear
    time complexity and we want the algorithm to be in-place as well!

    For example: input is [1,2,3,4,5] then the output is [5,4,3,2,1]
"""

arr = [1, 2, 3, 4, 5, 6]

for i in range(len(arr) // 2):
    arr[i], arr[len(arr)-1-i] = arr[len(arr)-1-i], arr[i]

print(arr)
