""" Josephus Circle using circular linked list
    URL: https://www.geeksforgeeks.org/josephus-circle-using-circular-linked-list/

    There are n people standing in a circle waiting to be executed. The
    counting out begins at some point in the circle and proceeds around the
    circle in a fixed direction. In each step, a certain number of people are
    skipped and the next person is executed. The elimination proceeds around
    the circle (which is becoming smaller and smaller as the executed people
    are removed), until only the last person remains, who is given freedom.
    Given the total number of persons n and a number m which indicates that
    m-1 persons are skipped and m-th person is killed in circle. The task is
    to choose the place in the initial circle so that you are the last one
    remaining and so survive.

    Example:
    Input: Length of circle: n = 4
           Count to choose next: m = 2
    Output : 1

    Input: n = 5
           m = 3
    Output: 4
"""

class Node:
    """ Node class contains everything related to Linked List node """
    def __init__(self, data):
        """ initializing single node with data """
        self.data = data
        self.next = None


class CircularLinkedList:
    """ Circular linked list is a linked list where all nodes are connected
        to form a circle.
    """
    def __init__(self):
        """ initializing circular linked list with zero node """
        self.head = None

    def __len__(self):
        """ get number of nodes currently present in circular linked list """
        if self.head is None:
            return 0

        current = self.head
        count = 1
        while current.next is not self.head:
            count += 1
            current = current.next
        return count

    def insert_tail(self, data):
        """ inserts node at the end of linked list """
        if self.head is None:
            self.head = Node(data)
            self.head.next = self.head
            return

        new_node = Node(data)
        current = self.head
        while current.next is not self.head:
            current = current.next
        current.next = new_node
        new_node.next = self.head

    def remove_node(self, node):
        """ remove node from circular linked list """
        if self.head == node:
            previous = self.head
            while previous.next is not self.head:
                previous = previous.next
            previous.next = self.head.next
            self.head = previous.next
            return

        current = self.head.next
        previous = self.head
        while current is not self.head:
            if current == node:
                break
            previous = current
            current = current.next
        previous.next = current.next

    def print(self):
        """ prints entire linked list without changing underlying data """
        current = self.head
        while current is not None:
            print(" ->", current.data, end="")
            current = current.next
            if current == self.head:
                break
        print(end=" -> ...")
        print()


def josephus_circle(cll, step):
    """ josephus circle solution """
    current = cll.head

    while len(cll) > 1:
        count = 1
        while count != step:
            current = current.next
            count += 1
        print("removing:", current.data)
        cll.remove_node(current)
        current = current.next


def main():
    """ operational function """
    total_people = 5
    step = 3

    cll = CircularLinkedList()
    for i in range(1, total_people+1):
        cll.insert_tail(i)
    cll.print()

    josephus_circle(cll, step)
    cll.print()


if __name__ == '__main__':
    main()
