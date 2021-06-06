""" Segment Tree is a data structure that allows answering range queries over an array effectively,
    while still being flexible enough to allow modifying the array. Time complexity for both queries
    i.e. range query and update query is O(log n)
"""

class SegmentTree:
    """ implementation of segment tree """
    def __init__(self, arr, func):
        """ segment tree initialization """
        self.arr = arr
        self.func = func
        self.size = len(arr)

        # If you have n values in the input array, the maximum number of
        # nodes in the segment tree array can not exceed 4n.
        self.seg_tree = [None] * (4 * self.size)

        self.build_segment_tree(0, self.size - 1, 0)

    def build_segment_tree(self, node_left, node_right, node_index):
        """ build segment tree from input array """
        if node_left > node_right:
            return

        if node_left == node_right:
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
        def _range_sum(query_left, query_right, node_left, node_right, node_index):
            """ internal recursive function """
            if node_left > node_right:
                return 0

            if node_right < query_left or node_left > query_right:
                return 0

            if query_left <= node_left and query_right >= node_right:
                return self.seg_tree[node_index]

            mid = node_left + (node_right - node_left) // 2
            left_child = node_index * 2 + 1
            right_child = node_index * 2 + 2

            left = _range_sum(query_left, query_right, node_left, mid, left_child)
            right = _range_sum(query_left, query_right, mid + 1, node_right, right_child)
            return self.func(left, right)

        return _range_sum(query_left, query_right, 0, self.size - 1, 0)

    def update(self, index, value):
        """ update segment tree """
        def _update(index, value, node_left, node_right, node_index):
            """ internal recursive function """
            if index < node_left or index > node_right:
                return

            if node_left == node_right:
                self.seg_tree[node_index] = value
                return

            mid = node_left + (node_right - node_left) // 2
            left_child = node_index * 2 + 1
            right_child = node_index * 2 + 2

            if index > mid:
                _update(index, value, mid + 1, node_right, right_child)
            else:
                _update(index, value, node_left, mid, left_child)

            self.seg_tree[node_index] = self.func(self.seg_tree[left_child], self.seg_tree[right_child])

        _update(index, value, 0, self.size - 1, 0)


def main():
    """ operational function """

    def addition(obj1, obj2):
        return obj1 + obj2

    st = SegmentTree([3, 5, 6, 10, 0, 1], addition)
    assert st.range_query(-1, 8) == 25
    assert st.range_query(2, 3) == 16
    st.update(4, 10)
    assert st.range_query(-1, 8) == 35
    assert st.range_query(2, 3) == 16


    def maximum(obj1, obj2):
        return obj1 if obj1 >= obj2 else obj2

    st = SegmentTree([3, 5, 6, 10, 0, 1], maximum)
    assert st.range_query(-1, 8) == 10
    assert st.range_query(2, 3) == 10
    st.update(4, 20)
    assert st.range_query(-1, 8) == 20
    assert st.range_query(2, 3) == 10


if __name__ == "__main__":
    main()
