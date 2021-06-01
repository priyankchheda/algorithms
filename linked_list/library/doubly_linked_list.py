""" Implementation of Doubly linked list Data Structure """

class Node:
    """ Node class contains everything related to linked list node """

    def __init__(self, data):
        """ initializing single node with data """
        self.data = data
        self.next = None
        self.previous = None


class DoublyLinkedList:
    """ A Doubly linked list (DLL) contains an extra pointer, typically
        called previous pointer, together with next pointer and data which
        are there in singly linked list.
    """
    def __init__(self):
        """ initializing doublt linked list with zero node """
        self.head = None

    def is_empty(self):
        """ returns True if the linked list is empty. Otherwise, return False.
        """
        return self.head is None

    def __len__(self):
        """ Traverses the linked list and returns an integer value representing
            the number of nodes in the linked list.

            The time complexity is O(n) because every node in the linked list
            must be visited in order to calculate the size of the linked list.
        """
        if self.head is None:
            return 0

        count = 0
        current = self.head

        # While there are still Nodes left to count
        while current is not None:
            count += 1
            current = current.next
        return count

    def insert_head(self, data):
        """ inserts node at the start of doubly linked list """
        if self.head is None:
            self.head = Node(data)
            return

        new_node = Node(data)
        current = self.head
        new_node.next = current
        current.previous = new_node
        self.head = new_node

    def insert_tail(self, data):
        """ inserts node at the end of doubly linked list """
        if self.head is None:
            self.head = Node(data)
            return

        current = self.head
        new_node = Node(data)
        while current.next is not None:
            current = current.next
        current.next = new_node
        new_node.previous = current

    def insert_at(self, position, data):
        """ inserts node at particular position in doubly linked list.
            index starts from 0.
        """
        dll_size = len(self)
        if position < 0 or position > dll_size:
            raise Exception("Invalid position")

        if position == dll_size:
            self.insert_tail(data)
            return

        if position == 0:
            self.insert_head(data)
            return

        current = self.head
        for _ in range(0, position):
            current = current.next

        new_node = Node(data)
        previous = current.previous
        previous.next = new_node
        current.previous = new_node
        new_node.next = current
        new_node.previous = previous

    def delete_head(self):
        """ removes first node and returns data. Raise exception,
            if doubly linked list is empty
        """
        if self.head is None:
            raise Exception("linked list is already empty")

        if self.head.next is None:
            self.head = None
            return

        self.head = self.head.next
        self.head.previous = None

    def delete_tail(self):
        """ removes last node and returns data. raise exception,
            if doubly linked list is empty
        """
        if self.head is None:
            raise Exception("linked list is already empty")

        if self.head.next is None:
            self.head = None
            return

        current = self.head
        while current.next is not None:
            current = current.next

        previous = current.previous
        current.previous = None
        previous.next = None
        del current

    def delete_at(self, position):
        """ removes specified node from doubly linked list and returns data.
            raise exception, if position is invalid.
        """
        dll_size = len(self)
        if position < 0 or position > dll_size:
            raise Exception("Invalid position")

        if position == 0:
            self.delete_head()
        elif position == dll_size:
            self.delete_tail()
        else:
            current = self.head
            for _ in range(0, position):
                current = current.next

            previous_node = current.previous
            next_node = current.next
            previous_node.next = next_node
            next_node.previous = previous_node
            del current

    def print(self):
        """ prints entire linked list without changing underlying data """
        current = self.head
        while current is not None:
            print(" <->", current.data, end="")
            current = current.next
        print()


def main():
    """ operational function """
    dll = DoublyLinkedList()
    print("is_empty?", dll.is_empty())
    dll.insert_head(3)
    print("is_empty?", dll.is_empty())
    dll.insert_head(2)
    dll.insert_head(1)
    dll.insert_tail(4)
    dll.insert_tail(5)
    dll.insert_tail(6)
    print("size?", len(dll))
    dll.print()

    dll.insert_at(3, 66)
    dll.print()

    print("deleting head")
    dll.delete_at(3)
    dll.print()


if __name__ == '__main__':
    main()
