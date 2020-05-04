/**
 * Dynamic Connectivity
 *
 * Given a set of N objects
 * - Union Command: connect two objects.
 * - Find/connected query: is there a path connecting the two objects?
 *
 * Quick-Find and Quick-Union are only going to tell us if there is a path
 * between two objects. It is not going to give us the complete path.
 *
 * Connected components: Maximal set of objects that are  mutually connected.
*/
#include <iostream>

/**
 * QuickUnion (Lazy Approach)
 * Data Structure: Integer array id[] of size N
 * Interpretation: id[i] is parent of i
 * Root/parent of i is id[id[id[...id[i]...]]]
 *
 * QuickUnion defect:
 * - Trees can get too tall
 * - Find too expensive (could be N array accesses)
*/
class QuickUnion {
private:
    int size;
    int* id;

    /**
     * Finding the root of element
     * @param elem element of which root is needed
     * @return root of elem
    */
    int root(int elem) {
        while (elem != id[elem])
            elem = id[elem];
        return elem;
    }

public:
    /**
     * Initializing list of size n where value is same as index
     * Time Complexity: O(n)
     * @param n number of elements
    */
    QuickUnion(int n): size(n) {
        id = new int[n];
        for (int i = 0; i < size; i++)
            id[i] = i;
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
     * @param p element 1
     * @param q element 2
    */
    void joinUnion(int p, int q) {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }
};

/* Main Driver Function */
int main()
{
    QuickUnion quickUnion(10);
    quickUnion.joinUnion(4, 3);
    quickUnion.joinUnion(3, 8);
    quickUnion.joinUnion(6, 5);
    quickUnion.joinUnion(9, 4);
    quickUnion.joinUnion(2, 1);
    std::cout << "is 0 connected to 7? " << quickUnion.connected(0, 7) << "\n";
    std::cout << "is 8 connected to 9? " << quickUnion.connected(8, 9) << "\n";
    quickUnion.joinUnion(5, 0);
    quickUnion.joinUnion(7, 2);
    quickUnion.joinUnion(6, 1);
    quickUnion.joinUnion(1, 0);
    std::cout << "is 0 connected to 7? " << quickUnion.connected(0, 7) << "\n";
    return 0;
}