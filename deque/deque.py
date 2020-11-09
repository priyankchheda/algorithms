""" Implementation for Deque Data Structure """


class Deque:
    """ Deque (double-ended queue) is an abstract data type that generalizes
    a queue, for which elements can be added to or removed from either the
    front (head) or back (tail).
    """

    def __init__(self):
        """ Initializing empty deque """
        self.items = []

    def add_front(self, item):
        """ Takes an item as a parameter and inserts it into the 0th index of
        the list that is representing the Deque.

        The runtime is linear, or O(n), because every time you insert into
        the front of a list, all the other items in the list need to shift
        one position to the right.
        """
        self.items.insert(0, item)

    def add_rear(self, item):
        """Takes in a item as a parameter and appends the item to the end of
        the list that is representing the deque.

        The runtime is constant because appending to the end of a list happens
        in constant time.
        """
        self.items.append(item)

    def remove_front(self):
        """ Removes and returns the item in the 0th index of the list, which
        represents the font of the Deque.

        The runtime is linear, or O(n), because when we remove an item from
        the 0th index, all the other items have to shift one index to the left.
        """
        if self.items:
            return self.items.pop(0)
        return None

    def remove_rear(self):
        """ Removes and returns the last item of the list, which represents
        the rear of the Deque.

        The runtime is constant because all we're doing is indexing to the
        end of a list.
        """
        if self.items:
            return self.items.pop()
        return None

    def peek_front(self):
        """  Returns the value found at the 0th index of the list, which
        represents the front of the Deque.

        The runtime is constant because all we're doing is indexing into
        a list.
        """
        if self.items:
            return self.items[0]
        return None

    def peek_rear(self):
        """ Returns the value found at the -1st, or last, index.

        The runtime is constant because all we're doing is indexing into a
        list.
        """
        if self.items:
            return self.items[-1]
        return None

    def size(self):
        """ Returns the length of the list, which is representing the deque.

        The runtime will be constant because all we're doing is finding the
        length of a list and returning that value.
        """
        return len(self.items)

    def is_empty(self):
        """ Checks to see if the list representing our Deque is empty. Returns
        True if it is, false if it isn't.

        The runtime is constant because all we're doing is comparing two
        values.
        """
        return self.items == []


def main():
    """ operational function """
    deque = Deque()
    print("deque is empty: ", deque.is_empty())
    print("deque size: ", deque.size())
    for i in range(5):
        deque.add_front(i)

    print("after inserting 5 elements")
    print("deque is empty: ", deque.is_empty())
    print("deque size: ", deque.size())

    print("top element on deque: ", deque.peek_front())
    print("back element on deque: ", deque.peek_rear())
    print("popped element from deque: ", deque.remove_front())
    print()
    print("after popping one elements")
    print("deque size: ", deque.size())
    print("top element on deque: ", deque.peek_front())


if __name__ == "__main__":
    main()
