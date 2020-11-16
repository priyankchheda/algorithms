""" Quick Find is a Eager Approach.

*Limitations:*

- Union is too expensive (N array accesses)
- Trees are flat, but too expensive to keep them flat
"""


class QuickFind:
    """ elem1 and elem2 are connected iff they have the same id """

    def __init__(self, n):
        """ Initializing list of size n where value is same as index
        Time Complexity: O(n)

        :param n: number of elements
        """
        self.data = []
        for i in range(n):
            self.data.append(i)

    def connected(self, elem1, elem2):
        """ elem1 and elem2 are connected iff they have the same id
        Time Complexity: O(1)

        :param elem1: element 1
        :param elem2: element 2
        :return: returns true iff two elem1 and elem2  are connected, else
            false
        :rtype: bool
        """
        return self.data[elem1] == self.data[elem2]

    def union(self, elem1, elem2):
        """ When connecting two objects elem1 and elem2, change the id of all
        objects that have the id of elem1 to that of elem2, or vice-versa.
        Time Complexity is O(n), which is too expensive.

        :param elem1: element 1
        :param elem2: element 2
        """
        pid = self.data[elem1]
        qid = self.data[elem2]
        for i in range(len(self.data)):
            if self.data[i] == pid:
                self.data[i] = qid


def main():
    """ operational function """
    maze = QuickFind(10)
    maze.union(4, 3)
    maze.union(3, 8)
    maze.union(6, 5)
    maze.union(9, 4)
    maze.union(2, 1)
    print("is 0-7 connected: ", maze.connected(0, 7))
    print("is 8-9 connected: ", maze.connected(8, 9))
    maze.union(5, 0)
    maze.union(7, 2)
    maze.union(6, 1)
    maze.union(1, 0)
    print("is 0-7 connected: ", maze.connected(0, 7))


if __name__ == "__main__":
    main()
