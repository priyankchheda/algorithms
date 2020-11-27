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
 * QuickFind (Eager Approach)
 * Data Structure: Integer array id[] of size N
 * Interpretation: p and q are connected iff they have same id.
 *
 * QuickFind defect: Union too expensive
 * Takes N^2 array accesses to process sequence of N union commands on
 * N objects.
*/
class QuickFind {
private:
    int size;
    int* id;
public:
    /**
     * Initializing list of size n where value is same as index
     * Time Complexity: O(n)
     * @param n number of elements
    */
    QuickFind(int n): size(n) {
        id = new int[n];
        for (int i = 0; i < size; i++)
            id[i] = i;
    }

    /**
     * p and q are connected iff they have the same id
     * Time Complexity: O(1)
     * @param p element 1
     * @param q element 2
     * @return true iff two p and q  are connected, else false
    */
    bool connected(int p, int q) {
        return id[p] == id[q];
    }

    /**
     * When connecting two objects elem1 and elem2, change the id of all
     * objects that have the id of elem1 to that of elem2, or vice-versa.
     * Time Complexity is O(n), which is too expensive.
     * @param p element 1
     * @param q element 2
    */
    void joinUnion(int p, int q) {
        int pid = id[p];
        int qid = id[q];
        for (int i = 0; i < size; i++) {
            if (id[i] == pid)
                id[i] = qid;
        }
    }
};

/* Main Driver Function */
int main()
{
    QuickFind quickFind(10);
    quickFind.joinUnion(4, 3);
    quickFind.joinUnion(3, 8);
    quickFind.joinUnion(6, 5);
    quickFind.joinUnion(9, 4);
    quickFind.joinUnion(2, 1);
    std::cout << "is 0 connected to 7? " << quickFind.connected(0, 7) << "\n";
    std::cout << "is 8 connected to 9? " << quickFind.connected(8, 9) << "\n";
    quickFind.joinUnion(5, 0);
    quickFind.joinUnion(7, 2);
    quickFind.joinUnion(6, 1);
    quickFind.joinUnion(1, 0);
    std::cout << "is 0 connected to 7? " << quickFind.connected(0, 7) << "\n";
    return 0;
}