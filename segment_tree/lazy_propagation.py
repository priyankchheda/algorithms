""" Segment Tree is a data structure that allows answering range queries over an array effectively,
    while still being flexible enough to allow modifying the array. Lazy propagation is used to
    update an interval from l to r, instead of a single element. Time complexity for both queries
    i.e. range query and update query is O(log n)
"""

class LazyPropagation:
    """ implementation of lazy propagation in segment tree """
    def __init__(self, arr, func):
        """ segment tree initialization """
        self.arr = arr
        self.func = func
        self.size = len(arr)

        # If you have n values in the input array, the maximum number of
        # nodes in the segment tree array can not exceed 4n.
        self.seg_tree = [None] * (4 * self.size)
        self.lazy_tree = [0] * (4 * self.size)

        self.build_segment_tree(0, self.size - 1, 0)

    def build_segment_tree(self, node_left, node_right, node_index):
        """ build segment tree from input array """
        if node_left > node_right:
            return

        if node_left == node_right: # base case
            self.seg_tree[node_index] = self.arr[node_left]
            return

        mid = node_left + (node_right - node_left) // 2
        left_child = node_index * 2 + 1
        right_child = node_index * 2 + 2
        self.build_segment_tree(node_left, mid, left_child)
        self.build_segment_tree(mid + 1, node_right, right_child)
        self.seg_tree[node_index] = self.func(self.seg_tree[left_child], self.seg_tree[right_child])

    def range_query(self, query_left, query_right):
        """ returns result for range queries """
        def _range_query(query_left, query_right, node_left, node_right, node_index):
            """ internal recursive function """
            if self.lazy_tree[node_index] != 0:
                # complete the pending update
                self.seg_tree[node_index] += self.lazy_tree[node_index]
                if node_left != node_right:
                    self.lazy_tree[2 * node_index + 1] += self.lazy_tree[node_index]
                    self.lazy_tree[2 * node_index + 2] += self.lazy_tree[node_index]
                self.lazy_tree[node_index] = 0

            # no overlap
            if node_left > node_right:
                return 0

            if node_right < query_left or node_left > query_right:
                return 0

            # complete overlap
            if query_left <= node_left and query_right >= node_right:
                return self.seg_tree[node_index]

            # partial overlap
            mid = node_left + (node_right - node_left) // 2
            left_child = node_index * 2 + 1
            right_child = node_index * 2 + 2

            left = _range_query(query_left, query_right, node_left, mid, left_child)
            right = _range_query(query_left, query_right, mid + 1, node_right, right_child)
            return self.func(left, right)

        return _range_query(query_left, query_right, 0, self.size - 1, 0)

    def range_update(self, query_left, query_right, value):
        """ update segment tree """
        def _range_update(query_left, query_right, value, node_left, node_right, node_index):
            """ internal recursive function """
            if self.lazy_tree[node_index] != 0:
                # complete the pending update
                self.seg_tree[node_index] += self.lazy_tree[node_index]
                if node_left != node_right:
                    self.lazy_tree[2 * node_index + 1] += self.lazy_tree[node_index]
                    self.lazy_tree[2 * node_index + 2] += self.lazy_tree[node_index]
                self.lazy_tree[node_index] = 0

            # no overlap
            if node_left > node_right:
                return 0

            if node_right < query_left or node_left > query_right:
                return 0

            # complete overlap
            if node_left >= query_left and node_right <= query_right:
                self.seg_tree[node_index] += value
                # if the current node is not leaf node
                if node_left != node_right:
                    self.lazy_tree[2 * node_index + 1] += value
                    self.lazy_tree[2 * node_index + 2] += value
                return

            # partial overlap
            mid = node_left + (node_right - node_left) // 2
            left_child = node_index * 2 + 1
            right_child = node_index * 2 + 2

            _range_update(query_left, query_right, value, mid + 1, node_right, right_child)
            _range_update(query_left, query_right, value, node_left, mid, left_child)

            self.seg_tree[node_index] = self.func(self.seg_tree[left_child], self.seg_tree[right_child])

        _range_update(query_left, query_right, value, 0, self.size - 1, 0)


def main():
    """ operational function """

    st = LazyPropagation([2, 4, 1, 6, 7], max)

    # add 4 to all the values in the range [3, 5]
    # after update: [2, 4, 1, 10, 11]
    st.range_update(3, 5, 4)

    # find the max value in range [2, 5]
    assert st.range_query(2, 5) == 11

if __name__ == "__main__":
    main()
