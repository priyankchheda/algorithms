""" Implementation for Queue Data Structure """


class Queue:
    """ Queue is a collection of entities that are maintained in a sequence
    and can be modified by the addition of entities at one end of the
    sequence and removal from the other end of the sequence.
    The order in which elements come off of a queue are
    First In, First Out (FIFO).
    https://en.wikipedia.org/wiki/Queue_(abstract_data_type)
    """

    def __init__(self):
        """ Initializing empty queue."""
        self.items = []

    def enqueue(self, item):
        """ Takes in an item and inserts that item into the 0th index of the
        list that is representing the Queue.

        The runtime is O(n), or linear time, because inserting into the 0th
        index of a list forces all the other items in the list to move one
        index to the right.

        :param item: item to be inserted in queue
        """
        self.items.insert(0, item)

    def dequeue(self):
        """ Returns and removes the front-most item of the Queue, which is
        represented by the last items in the list.

        The runtime is O(1), or constant time, because indexing to the end of
        a list happens in constant time.

        :return: front-most item of the queue or None, if the queue is empty
        """
        if not self.items:
            raise IndexError('queue is empty')
        return self.items.pop()

    def peek(self):
        """ Returns the last item in the list, which represents the front-most
        item in the Queue.

        The runtime is O(1), or constant time, because we are just indexing to
        the last item of the list and returning the value found there.

        :return: front-most item of the queue or None, if the queue is empty
        """
        if not self.items:
            raise IndexError('queue is empty')
        return self.items[-1]

    def size(self):
        """ Returns the size of the Queue, which is represent bu the length
        of the list

        The runtime is O(1), or constant time, because we're only returning
        the length.

        :return: length of list
        :rtype: int """
        return len(self.items)

    def is_empty(self):
        """ Returns a boolean value expressing whether or not the list
        representing the Queue is empty.

        Runs in constant time, because it's only checking for equality.

        :return: returns true if stack is empty, else false
        """
        return self.items == []
