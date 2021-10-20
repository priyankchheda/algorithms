""" The problem is that we want to reverse a T[] array in O(N) linear
    time complexity and we want the algorithm to be in-place as well!

    For example: input is [1,2,3,4,5] then the output is [5,4,3,2,1]
"""

def iterative_reverse(arr):
    """ reverse a list using iterative approach """
    start = 0
    end = len(arr) - 1
    while start < end:
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1


def recursive_reverse(arr, start, end):
    """ reverse a list using recursive approach """
    if start < end:
        arr[start], arr[end] = arr[end], arr[start]
        recursive_reverse(arr, start + 1, end - 1)


def python_slicing_reverse(arr):
    """ reverse list using python list slicing """
    return arr[::-1]


def main():
    """ operational function """
    arr = [1, 2, 3, 4, 5, 6]
    iterative_reverse(arr)
    assert arr == [6, 5, 4, 3, 2, 1]

    arr = [1, 2, 3, 4, 5]
    recursive_reverse(arr, 0, len(arr) - 1)
    assert arr == [5, 4, 3, 2, 1]

    arr = [1, 2, 3, 4, 5]
    arr = python_slicing_reverse(arr)
    assert arr == [5, 4, 3, 2, 1]


if __name__ == '__main__':
    main()
