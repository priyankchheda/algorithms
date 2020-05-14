/*
 * Red Black Tree is an implementation for left leaning red black tree
 * data structure in go language.
 *
 * Red-Black Tree is a self-balancing Binary Search Tree (BST) where every node
 * has a color either red or black. Root of tree is always black. There are no
 * two adjacent red nodes (A red node cannot have a red parent or red child).
 * Every path from a node (including root) to any of its descendant NULL node has
 * the same number of black nodes.
 *
 * Why Red-Black Trees
 *
 * Most of the BST operations (e.g., search, max, min, insert, delete.. etc)
 * take O(h) time where h is the height of the BST. The cost of these
 * operations may become O(n) for a skewed Binary tree. If we make sure that
 * height of the tree remains O(Logn) after every insertion and deletion, then
 * we can guarantee an upper bound of O(Logn) for all these operations. The
 * height of a Red-Black tree is always O(Logn) where n is the number of nodes
 * in the tree.
 *
 * The main problem with BST deletion (Hibbard Deletion) is that It is not
 * symmetric. After many insertion and deletion BST become less balance.
 * Researchers proved that after sufficiently long number of random insert
 * and delete height of the tree becomes sqrt(n) .So now every operation
 * (search, insert, delete) will take sqrt(n) time which is not good compare
 * to O(logn) .
 *
 * This is very long standing(around 50 years) open problem to efficient
 * symmetric delete for BST. for guaranteed balanced tree, we have to use
 * RedBlack Tree etc.
 *
 * Properties
 *  - No Node has two red links connected to it.
 *  - Every path from root to null link has the same number of black links.
 *  - Red links lean left.
*/

#ifndef RBTREE_H
#define RBTREE_H

#include <exception>

class EmptyTree : public std::exception {
    const char* what() const throw() {
        return "tree is empty";
    }
};

// Red Black Node contains actual data and color bit along with links to left,
// right, parent node
struct Node {
    int data;
    int color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int _data, int _color) {
        data = _data;
        color = _color;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class RedBlackTree {
private:
    Node* root;
    bool find(Node* node, int data);
    // void deleteTreeRecursive(Node* node);
    // void leftRotate(Node* node);
    // void rightRotate(Node* node);
    // void replaceNode(Node* node);

public:
    RedBlackTree() { root = nullptr; }
    // ~RedBlackTree() { deleteTreeRecursive(root); }
    Node* getRoot() { return root; }
    // void insert(int data);
    bool find(int data);
    int min();
    int max();
};

#endif