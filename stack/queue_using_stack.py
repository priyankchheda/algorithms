"""
Problem Statement:
We are given a stack data structure with push and pop operations, the task is
to implement a queue using instances of stack data structure and operations
on them.

URL: https://www.geeksforgeeks.org/queue-using-stacks/
"""

class Queue:
    """ Queue implementation using two Stacks """
    def __init__(self):
        self.stack = []
        self.aux_stack = []

    def enqueue(self, element):
        """ enqueue element to queue """
        while self.stack:
            self.aux_stack.append(self.stack.pop())
        self.aux_stack.append(element)

        while self.aux_stack:
            self.stack.append(self.aux_stack.pop())

    def dequeue(self):
        """ dequeue element to queue """
        if not self.stack:
            raise IndexError("queue is empty")
        return self.stack.pop()


def main():
    """ operational function """
    queue = Queue()
    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)
    print(queue.dequeue())
    print(queue.dequeue())
    print(queue.dequeue())

    queue.enqueue(4)
    queue.enqueue(5)
    print(queue.dequeue())
    print(queue.dequeue())
    try:
        print(queue.dequeue())
    except IndexError as err:
        print(err)


if __name__ == '__main__':
    main()
