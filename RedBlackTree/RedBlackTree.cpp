#include <iostream>
#include "RedBlackTree.hpp"

/**
 * find the element in red black tree
 * @param data item to be searched
*/
bool RedBlackTree::find(int data) {
    if (root == nullptr)
        return false;

    return find(root, data);
}

/**
 * find is an recursive internal method which works at node level
 * @param root root of tree/sub-tre
 * @param data item to be searched
*/
bool RedBlackTree::find(Node* node, int data) {
    if (root == nullptr)
        return false;

    if (data == root->data) return true;
    else if (data < root->data) return find(root->left, data);
    else return find(root->right, data);
}

/**
 * returns left-most item present in red black tree which is also
 * the minimum element in red black tree
 * @return minimum element present in red black tree
*/
int RedBlackTree::min()
{
    Node* root = getRoot();
    if (root == nullptr)
        throw EmptyTree();

    Node* current = root;
    while (current->left != nullptr)
        current = current->left;

    return current->data;
}

/**
 * returns right-most item present in red black tree which is also
 * the maximum element in red black tree
 * @return maximum element present in red black tree
*/
int RedBlackTree::max()
{
    Node* root = getRoot();
    if (root == nullptr)
        throw EmptyTree();

    Node* current = root;
    while (current->right != nullptr)
        current = current->right;

    return current->data;
}