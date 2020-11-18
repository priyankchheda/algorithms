""" check if linked list is palindrome or not
"""

class Node:
    """ Node class contains everything related to Linked List node """
    def __init__(self, data):
        """ initializing single node with data """
        self.data = data
        self.next = None


class LinkedList:
    """ Singly Linked List is a linear data structure """
    def __init__(self):
        """ initializing singly linked list with zero node """
        self.head = None

    def insert_head(self, data):
        """ inserts node at the start of linked list """
        node = Node(data)
        node.next = self.head
        self.head = node

    def print(self):
        """ prints entire linked list without changing underlying data """
        current = self.head
        while current is not None:
            print(" ->", current.data, end="")
            current = current.next
        print()


    def is_palindrome(self):
        """ removes duplicates from list """
        stack = []
        current = self.head

        while current is not None:
            stack.append(current.data)
            current = current.next

        current = self.head
        for _ in range(len(stack)//2):
            if stack.pop() != current.data:
                return False
            current = current.next

        return True


def main():
    """ operational function """
    linkedlist = LinkedList()
    linkedlist.insert_head(4)
    linkedlist.insert_head(2)
    linkedlist.insert_head(2)
    linkedlist.insert_head(1)
    linkedlist.insert_head(2)
    linkedlist.insert_head(2)
    linkedlist.insert_head(4)

    linkedlist.print()
    print(linkedlist.is_palindrome())


if __name__ == '__main__':
    main()
