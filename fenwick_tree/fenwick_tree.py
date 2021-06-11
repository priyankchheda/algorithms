""" A Fenwick tree or binary indexed tree is a data structure that can
    efficiently update elements and calculate prefix sums in a table of
    numbers.

    space complexity for fenwick tree is O(n)
    time complexity to create fenwick tree is O(nlogn)
    time complexity to update value is O(logn)
    time complexity to get prefix sum is O(logn)

    * References
    http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
    https://www.youtube.com/watch?v=CWDQJGaN1gY
"""

class FenwickTree:
    """ implementation of fenwick tree """
    def __init__(self, arr):
        """ fenwick tree initialization """
        self.arr = arr
        self.size = len(self.arr)
        self.bi_tree = [0] * (self.size + 1)
        self.build_fenwick_tree()

    def build_fenwick_tree(self):
        """ build fenwick tree from input array """
        for i in range(self.size):
            self.update(i, self.arr[i])

    def update(self, index, value):
        """ updates the binary indexed tree with the given value """
        index = index + 1
        while index < len(self.bi_tree):
            self.bi_tree[index] += value
            index += index & -index

    def get_sum(self, index):
        """ calculates the sum of the elements from the beginning to the index
        """
        result = 0
        index = index + 1
        while index > 0:
            result += self.bi_tree[index]
            index -= index & -index
        return result

    def get_range_sum(self, left, right):
        """ calculates the sum from the given range """
        return self.get_sum(right) - self.get_sum(left - 1)


def main():
    """ operational function """
    f_tree = FenwickTree([3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3])
    assert 3 == f_tree.get_sum(0)
    assert 5 == f_tree.get_sum(1)
    assert 4 == f_tree.get_sum(2)
    assert 10 == f_tree.get_sum(3)
    assert 15 == f_tree.get_sum(4)
    assert 19 == f_tree.get_sum(5)
    assert 16 == f_tree.get_sum(6)

    assert f_tree.get_range_sum(2, 4) == 10
    assert f_tree.get_range_sum(1, 4) == 12
    assert f_tree.get_range_sum(2, 6) == 11
    assert f_tree.get_range_sum(0, 1) == 5

    f_tree.update(3, 10)
    f_tree.update(0, 5)

    assert 8 == f_tree.get_sum(0)
    assert f_tree.get_range_sum(2, 4) == 20
    assert f_tree.get_range_sum(1, 4) == 22
    assert f_tree.get_range_sum(2, 6) == 21
    assert f_tree.get_range_sum(0, 1) == 10


if __name__ == '__main__':
    main()
