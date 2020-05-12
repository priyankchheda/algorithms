/**
 * check whether the given binary tree is Binary Search Tree or not.
*/
#include <iostream>
#include <limits>
#include "BST/BST.hpp"

/* Function Declarations */
bool isBST(Node* root);
bool isBSTUtil(Node* root, int minValue, int maxValue);

/* Main Operational Function */
int main()
{
    BST tree1;
    int original[] = { 9, 5, 3, 10, 6, 1, 7, 4 };
    for (int i : original)
        tree1.insert(i);
    std::cout << "is tree1 bst? " << isBST(tree1.getRoot()) << "\n";

    BST tree2;
    tree2.insert(5);
    Node* root = tree2.getRoot();
    root->right = new Node(7);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    std::cout << "is tree2 bst? " << isBST(tree2.getRoot()) << "\n";

    return 0;
}

/**
 * checks if binary tree is BST
 * @param root root of binary (sub)tree
 * @return true if binary (sub)tree is BST, else false
*/
bool isBST(Node* root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

/**
 * binary search tree check utility function
 * @param root root of binary (sub)tree
 * @param minValue tree nodes should be greater than minValue
 * @param maxValue tree nodes should be less than maxValue
 * @return true if binary (sub)tree is BST, else false
*/
bool isBSTUtil(Node* root, int minValue, int maxValue)
{
    if (root == nullptr)
        return true;

    if (root->data >= minValue && root->data < maxValue
        && isBSTUtil(root->left, minValue, root->data)
        && isBSTUtil(root->right, root->data, maxValue))
        return true;
    return false;
}
