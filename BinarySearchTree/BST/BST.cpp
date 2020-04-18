#include "BST.hpp"

/**
 * inserts new integer data into the tree at the position, so that
 * the binary search tree property is maintained.
 * @param data new integer data to be inserted
*/
void BST::insert(int data)
{
    if (root == nullptr) {
        root = new Node(data);
    } else {
        root = insert(root, data);
    }
}

/**
 * insert is an recursive internal method which works on node level
 * @param data new integer data to be inserted
*/
Node* BST::insert(Node* root, int data)
{
    if (root == nullptr) {
        root = new Node(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

/**
 * finds the integer in binary search tree
 * @param data item to be searched
*/
bool BST::search(int data)
{
    if (root == nullptr)
        return false;

    return search(root, data);
}

/**
 * search is an recursive internal method which works at node level
 * @param root root of tree/sub-tre
 * @param data item to be searched
*/
bool BST::search(Node* root, int data)
{
    if (root == nullptr)
        return false;

    if (data == root->data) return true;
    else if (data < root->data) return search(root->left, data);
    else return search(root->right, data);
}
