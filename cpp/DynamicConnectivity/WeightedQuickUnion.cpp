/**
 * """ QuickFind and QuickUnion algorithms are easy to implement,
 * but simply can't support huge dynamic connectivity problems.
 *
 * Improvement 1: Weighting
 * - modify quick union to avoid tall trees
 * - keep track of size of each tree (number of objects)
 * - balance by linking root of smaller tree to root of larger tree
 *
 * Improvement 2: Path Compression
 * Just after computing the root of p, set the id of each examined node to
 * point to that root.
 *
 * Implementation of path compression:
 * - Two-pass Implementation: add second loop to root() to set the id[] of each
 *   examined node to the root.
 * - Simpler one-pass variant: Make every other node in path point to its
 *   grandparent (thereby halving path length) [implmented in this script]
*/

/**
 * Optimized version of Quick Union
 * Same as quick-union, but maintain extra array sz_count[i] to count
 * number of objects in the tree rooted at i
*/
#include <iostream>

class WeightedQuickUnion {
private:
    int size;
    int* id;
    int* sz;

    /**
     * Finding the root of element
     * @param elem element of which root is needed
     * @return root of elem
    */
    int root(int elem) {
        while (elem != id[elem]) {
            // path compression optimization
            id[elem] = id[id[elem]];
            elem = id[elem];
        }
        return elem;
    }

public:
    /**
     * Initializing list of size n where value is same as index.
     * Here it means that each node is a root of it's own tree
     * Time Complexity: O(n)
     * @param n number of elements
    */
    WeightedQuickUnion(int n): size(n) {
        id = new int[n];
        sz = new int[n];
        for (int i = 0; i < size; i++) {
            id[i] = i;
            sz[i] = 0;
        }
    }

    /**
     * p and q are connected iff they have same root
     * @param p element 1
     * @param q element 2
     * @return true iff two p and q are connected, else false
    */
    bool connected(int p, int q) {
        return root(p) == root(q);
    }

    /**
     * To merge components containing p and q, set the id of p's
     * root to the id of q's root
     * modify quick-union to:
     * - link root of smaller tree to root of larger tree
     * - update the sz_count[] array
     * Time complexity is lg N. Depth of any node x is at most lg N.
     * @param p element 1
     * @param q element 2
    */
    void joinUnion(int p, int q) {
        int i = root(p);
        int j = root(q);
        if (i == j) return;
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = id[i];
            sz[i] += sz[j];
        }
    }
};

/* Main Driver Function */
int main()
{
    WeightedQuickUnion weightedQuickUnion(10);
    weightedQuickUnion.joinUnion(4, 3);
    weightedQuickUnion.joinUnion(3, 8);
    weightedQuickUnion.joinUnion(6, 5);
    weightedQuickUnion.joinUnion(9, 4);
    weightedQuickUnion.joinUnion(2, 1);
    std::cout << "is 0 connected to 7? " << weightedQuickUnion.connected(0, 7) << "\n";
    std::cout << "is 8 connected to 9? " << weightedQuickUnion.connected(8, 9) << "\n";
    weightedQuickUnion.joinUnion(5, 0);
    weightedQuickUnion.joinUnion(7, 2);
    weightedQuickUnion.joinUnion(6, 1);
    weightedQuickUnion.joinUnion(1, 0);
    std::cout << "is 0 connected to 7? " << weightedQuickUnion.connected(0, 7) << "\n";
    return 0;
}