""" Implementation of Max Heap Data Structure """


class MaxHeap:
    """ Max Heap is a complete binary tree.
    In Max Heap, the key at root must be maximum among all keys
    present in Binary Heap. The same property must be recursively true for
    all nodes in Binary Tree.
    """

    def __init__(self):
        """ initialize new empty 1-indexed heap """
        self.data = [None]

    def length(self):
        """ returns total number of items present in heap """
        return len(self.data) - 1

    def is_empty(self):
        """ checks if heap is empty or not """
        return self.length() == 0

    def insert(self, item):
        """ inserts new item into heap while maintaining heap invariant """
        self.data.append(item)
        self.swim(self.length())

    def get_max(self):
        """ get_max returns the maximum value (i.e. root) in the heap,
        without removing it. Returns None, if the heap is empty.
        """
        if self.is_empty():
            return None
        return self.data[1]

    def extract_max(self):
        """ extract_max returns the maximum value (i.e. root) in the heap
        and removes it from the heap. Returns None, if heap is empty.
        """
        if self.is_empty():
            return None

        max_value = self.data[1]
        self.data[1] = self.data[self.length()]
        self.data = self.data[:self.length()]
        self.sink(1)
        return max_value

    def swim(self, index):
        """ swim moves element at index upward to maintain heap invariant """
        if index <= 1:
            return

        parent = index // 2
        if self.data[parent] < self.data[index]:
            self.data[parent], self.data[index] = self.data[index], self.data[parent]
            self.swim(parent)

    def sink(self, index):
        """ sink moves element at index downward to maintain heap invariant """
        max_index = index
        left = index * 2
        right = (index * 2) + 1

        if left <= self.length():
            if self.data[max_index] < self.data[left]:
                max_index = left

        if right <= self.length():
            if self.data[max_index] < self.data[right]:
                max_index = right

        if max_index != index:
            self.data[index], self.data[max_index] = self.data[max_index], self.data[index]
            self.sink(max_index)


def main():
    """ operational function """
    mheap = MaxHeap()
    mheap.insert(5)
    mheap.insert(3)
    print(mheap.get_max())
    mheap.insert(1)
    mheap.insert(6)
    mheap.insert(2)
    print(mheap.data)
    print(mheap.extract_max())
    print(mheap.data)
    print(mheap.extract_max())
    mheap.insert(3)
    print(mheap.extract_max())
    print(mheap.extract_max())
    print(mheap.extract_max())
    print(mheap.data)


if __name__ == "__main__":
    main()
