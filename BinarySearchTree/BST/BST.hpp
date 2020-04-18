/**
 * Binary Search Tree (C++ Implementation)
 *
 * Binary Search Tree is a node-based binary tree data structure
 * which has the following properties:
 * - The left subtree of a node contains only nodes with keys lesser
 *   than the node’s key.
 * - The right subtree of a node contains only nodes with keys greater
 *   than the node’s key.
 * - The left and right subtree each must also be a binary search tree.
*/

#ifndef BST_H
#define BST_H

#include <exception>

class EmptyTree : public std::exception {
    const char* what() const throw() {
        return "tree is empty";
    }
};

// Node struct contains actual data and address to left and right node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int _data) {
        data = _data;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;
    Node* insert(Node* root, int data);
    bool search(Node* root, int data);

public:
    BST() { root = nullptr; }
    Node* getRoot() { return root; }
    void insert(int data);
    bool search(int data);
    int min();
    int max();
};

#endif
