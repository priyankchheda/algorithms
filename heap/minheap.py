""" Implementation of Min Heap Data Structure """


class MinHeap:
    """ MinHeap is a complete binary tree.
    In MinHeap, the key at root must be minimum among all keys
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

    def get_min(self):
        """ get_min returns the minimum value (i.e. root) in the heap,
        without removing it. Returns None, if the heap is empty.
        """
        if self.is_empty():
            return None
        return self.data[1]

    def extract_min(self):
        """ extract_min returns the minimum value (i.e. root) in the heap
        and removes it from the heap. Returns None, if heap is empty.
        """
        if self.is_empty():
            return None

        min_value = self.data[1]
        self.data[1] = self.data[self.length()]
        self.data = self.data[:self.length()]
        self.sink(1)
        return min_value

    def swim(self, index):
        """ swim moves element at index upward to maintain heap invariant """
        if index <= 1:
            return

        parent = index // 2
        if self.data[parent] > self.data[index]:
            self.data[parent], self.data[index] = self.data[index], self.data[parent]
            self.swim(parent)

    def sink(self, index):
        """ sink moves element at index downward to maintain heap invariant """
        min_index = index
        left = index * 2
        right = (index * 2) + 1

        if left <= self.length():
            if self.data[min_index] > self.data[left]:
                min_index = left

        if right <= self.length():
            if self.data[min_index] > self.data[right]:
                min_index = right

        if min_index != index:
            self.data[index], self.data[min_index] = self.data[min_index], self.data[index]
            self.sink(min_index)


def main():
    """ operational function """
    mheap = MinHeap()
    mheap.insert(5)
    mheap.insert(3)
    print(mheap.get_min())
    mheap.insert(1)
    mheap.insert(6)
    mheap.insert(2)
    print(mheap.data)
    print(mheap.extract_min())
    print(mheap.data)
    print(mheap.extract_min())
    mheap.insert(3)
    print(mheap.extract_min())
    print(mheap.extract_min())
    print(mheap.extract_min())
    print(mheap.data)


if __name__ == "__main__":
    main()
