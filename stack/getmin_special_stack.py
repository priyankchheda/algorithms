"""
Problem Statement:
Design a Data Structure SpecialStack that supports all the stack operations
like push(), pop(), isEmpty(), isFull() and an additional operation getMin()
which should return minimum element from the SpecialStack. All these
operations of SpecialStack must be O(1). To implement SpecialStack, you
should only use standard Stack data structure and no other data structure
like arrays, list, .. etc.

URL: https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/
"""

class SpecialStack:
    """ special stack with get_min functionality """
    def __init__(self):
        self.data = []
        self.aux_min = []

    def push(self, element):
        """ push element into stack """
        if not self.data:
            self.aux_min.append(element)
        else:
            self.aux_min.append(min(self.aux_min[-1], element))
        self.data.append(element)

    def pop(self):
        """ pop element from stack """
        if not self.data:
            raise IndexError("stack is empty")
        self.aux_min.pop()
        return self.data.pop()

    def get_min(self):
        """ returns minimum element present in stack
            Time complexity: O(1)
        """
        if self.aux_min:
            return self.aux_min[-1]
        return None


def main():
    """ operational function """
    ss = SpecialStack()
    ss.push(30)
    ss.push(20)
    ss.push(10)
    print(ss.get_min())
    ss.push(5)
    print(ss.get_min())

    ss.pop()
    print(ss.get_min()) # 10
    ss.pop()
    print(ss.get_min()) # 20
    ss.pop()
    print(ss.get_min()) # 30
    ss.pop()
    print(ss.get_min()) # None


if __name__ == "__main__":
    main()
