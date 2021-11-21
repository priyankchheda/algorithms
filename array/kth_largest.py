"""
Given an array arr[] and an integer K where K is smaller than size of array,
the task is to find the Kth smallest element in the given array.
It is given that all array elements are distinct.

Input: arr[] = 7 10 4 3 20 15; K = 3
Output: 7
Explanation: 3rd smallest element in the given array is 7.

Solution: We are going to solve this using quick select algorithm
"""

class QuickSelect:
    """ QuickSelect is a selection algorithm to find the k-th smallest element in
        an unordered list. It is related to the quick sort sorting algorithm.
    """
    def __init__(self, arr, k):
        self.arr = arr
        self.k = k

    def partition(self, low, high):
        """ return partition index of pivot """
        idx = low
        j = low
        while j < high:
            if self.arr[j] <= self.arr[high]:
                self.arr[idx], self.arr[j] = self.arr[j], self.arr[idx]
                idx += 1
            j += 1
        self.arr[idx], self.arr[high] = self.arr[high], self.arr[idx]
        return idx

    def run(self, low, high):
        """ main quick select algorithm """
        if self.k >= len(self.arr):
            raise Exception('k can not be larger than array length')

        while low < high:
            pivot = self.partition(low, high)
            if pivot < self.k:
                low = pivot + 1
            elif pivot > self.k:
                high = pivot - 1
            else:
                return self.arr[self.k]
        return self.arr[self.k]


def kth_largest(arr, k):
    """ returns kth largest element in the array """
    qs = QuickSelect(arr, k - 1)
    return qs.run(0, len(arr) - 1)


def main():
    """ operational function """
    assert kth_largest([7, 10, 4, 3, 20, 15], 1) == 3
    assert kth_largest([7, 10, 4, 3, 20, 15], 3) == 7
    assert kth_largest([7, 10, 4, 3, 20, 15], 6) == 20


if __name__ == '__main__':
    main()
