""" QuickFind and QuickUnion algorithms are easy to implement,
but simply can't support huge dynamic connectivity problems.

*Improvement 1:* **Weighting**

- modify quick union to avoid tall trees
- keep track of size of each tree (number of objects)
- balance by linking root of smaller tree to root of larger tree

*Improvement 2:* **Path Compression**

Just after computing the root of p, set the id of each examined node to
point to that root.

**Implementation of path compression:**

- Two-pass Implementation: add second loop to root() to set the id[] of each
  examined node to the root.
- Simpler one-pass variant: Make every other node in path point to its
  grandparent (thereby halving path length) [implmented in this script]
"""


class WeightedQuickUnion:
    """ Same as quick-union, but maintain extra array sz_count[i] to count
    number of objects in the tree rooted at i
    """

    def __init__(self, n):
        """ Initializing list of size n where value is same as index
        Here it means that each node is a root of it's own tree
        Time Complexity: O(n)

        :param n: number of elements
        """
        self.data = []
        self.sz_count = []
        for i in range(n):
            self.data.append(i)
            self.sz_count.append(0)

    def root(self, elem):
        """ Finding the root of element

        :param elem: element of which root is needed
        :return: root of elem
        """
        while elem != self.data[elem]:
            # only one extra line for path compression
            self.data[elem] = self.data[self.data[elem]]
            elem = self.data[elem]
        return elem

    def connected(self, elem1, elem2):
        """ elem1 and elem2 are connected iff they have same root. It takes
        time proportional to depth of elem1 and elem2. Time complexity is lg(N)

        :param elem1: element 1
        :param elem2: element 2
        :return: returns true iff two elem1 and elem2  are connected, else
            false
        :rtype: bool
        """
        return self.root(elem1) == self.root(elem2)

    def union(self, elem1, elem2):
        """ To merge components containing elem1 and elem2, set the id of
        elem1's root to the id of elem2's root.
        modify quick-union to:

        - link root of smaller tree to root of larger tree
        - update the sz_count[] array

        Time complexity is lg N. Depth of any node x is at most lg N.

        :param elem1: element 1
        :param elem2: element 2
        """
        root_elem1 = self.root(elem1)
        root_elem2 = self.root(elem2)
        if root_elem1 == root_elem2:
            return

        if self.sz_count[root_elem1] < self.sz_count[root_elem2]:
            self.data[root_elem1] = root_elem2
            self.sz_count[root_elem2] += self.sz_count[root_elem1]
        else:
            self.data[root_elem2] = root_elem1
            self.sz_count[root_elem1] += self.sz_count[root_elem2]


def main():
    """ operational function """
    maze = WeightedQuickUnion(10)
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
