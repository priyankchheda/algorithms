""" Implementation of Singly Linked List Data Structure """


class Node:
    """ Node class contains everything related to Linked List node """

    def __init__(self, data):
        """ initializing single node with data """
        self.data = data
        self.next = None

    def __repr__(self):
        return f"Node: data={self.data}"

    def get_data(self):
        """ Return the self.data attribute. """
        return self.data

    def set_data(self, new_data):
        """ replace the existing value of the self.data attribute with
            new_data parameter
        """
        self.data = new_data

    def get_next(self):
        """ return the self.next attribute. """
        return self.next

    def set_next(self, new_next):
        """ replace the existing value of the self.next attribute with
            new_next parameter
        """
        self.next = new_next


class LinkedList:
    """ Singly Linked List is a linear data structure.
        Unlike arrays, linked list elements are not stored at a contiguous
        location; the elements are linked using pointers.
    """

    def __init__(self):
        """ initializing singly linked list with zero node """
        self.head = None

    def __len__(self):
        """ returns the number of nodes currently present in linked list """
        current = self.head
        count = 0
        while current is not None:
            count = count + 1
            current = current.get_next()
        return count

    def __repr__(self):
        return f"LinkedList: head={self.head}"

    def get_head(self):
        """ returns the first linked list node """
        return self.head

    def is_empty(self):
        """ returns true if the Linked List is empty. Otherwise, return false
        """
        return self.__len__() == 0

    def insert_head(self, data):
        """ inserts node at the start of linked list """
        node = Node(data)
        node.set_next(self.head)
        self.head = node

    def insert_tail(self, data):
        """ inserts node at the end of linked list """
        node = Node(data)
        if self.head is None:
            self.head = node
        else:
            current = self.head
            while current.get_next() is not None:
                current = current.get_next()
            current.set_next(node)

    def insert_at(self, data, position):
        """ inserts node at specified position in linked list """
        length = self.__len__()
        if position <= 1:
            self.insert_head(data)
        elif position >= length:
            self.insert_tail(data)
        else:
            node = Node(data)
            previous = self.head
            current = self.head
            for _ in range(1, position):
                previous = current
                current = current.get_next()
            previous.set_next(node)
            node.set_next(current)

    def delete_head(self):
        """ removes first linked list node and returns data. Raise exception,
            if linkedlist is empty
        """
        if self.head is None:
            raise IndexError("linkedlist is empty")
        node = self.head
        data = node.get_data()
        self.head = self.head.get_next()
        return data

    def delete_tail(self):
        """ removes last linked list node and returns data. raise exception,
            if linkedlist is empty
        """
        if self.head is None:
            raise IndexError("linkedlist is empty")
        current = self.head
        if current.get_next() is None:
            self.head = None
        else:
            previous = self.head
            while current.get_next() is not None:
                previous = current
                current = current.get_next()
            previous.set_next(None)
        return current.get_data()

    def delete_at(self, position):
        """ removes specified node from linked list and returns data.
            raise exception, if position is invalid.
        """
        length = self.__len__()
        if position < 1 or position > length:
            raise ValueError("invalid position")

        if position == 1:
            return self.delete_head()
        elif position == length:
            return self.delete_tail()
        else:
            previous = self.head
            current = self.head
            for _ in range(1, position):
                previous = current
                current = current.get_next()
            removed_data = current.get_data()
            previous.set_next(current.get_next())
            current.set_next(None)
            return removed_data

    def data_at(self, position):
        """ returns node data without removing it.
            raise exception, if position is invalid.
        """
        length = self.__len__()
        if position < 1 or position > length:
            raise ValueError("invalid position")

        current = self.head()
        for _ in range(1, position):
            current = current.get_next()
        return current.get_data()

    def print(self):
        """ prints entire linked list without changing underlying data """
        current = self.head
        while current is not None:
            print(" -> ", current.get_data())
            current = current.get_next()
        print()
