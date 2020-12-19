"""
Problem Statement:
Implementation of twoStacks should use only one array, i.e., both stacks
should use the same array for storing elements.

URL: https://www.geeksforgeeks.org/implement-two-stacks-in-an-array/
"""

class TwoStacks:
    def __init__(self, capacity):
        self.arr = [None] * capacity
        self.index1 = -1
        self.index2 = capacity

    def push1(self, element1):
        """ push element to stack 1 """
        self.index1 += 1
        if self.index1 >= self.index2:
            self.index1 -= 1
            raise IndexError("array is full")
        self.arr[self.index1] = element1


    def push2(self, element2):
        """ push element to stack 2 """
        self.index2 -= 1
        if self.index1 >= self.index2:
            self.index2 += 1
            raise IndexError("array is full")
        self.arr[self.index2] = element2

    def pop1(self):
        """ pop element from stack 1 """
        popped_element = self.arr[self.index1]
        self.arr[self.index1] = None
        self.index1 -= 1
        return popped_element

    def pop2(self):
        """ pop element from stack 2 """
        popped_element = self.arr[self.index2]
        self.arr[self.index2] = None
        self.index2 += 1
        return popped_element


def main():
    """ operational function """
    ts = TwoStacks(5)
    ts.push1(5)
    ts.push2(10)
    ts.push2(15)
    ts.push1(11)
    ts.push2(7)

    print(ts.pop1())
    ts.push2(40)
    print(ts.pop2())
    print(ts.arr) # [5, None, 7, 15, 10]


if __name__ == "__main__":
    main()

