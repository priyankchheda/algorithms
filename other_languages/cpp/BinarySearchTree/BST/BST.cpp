#include "BST.hpp"
#include <iostream>

/**
 * Delete tree nodes recursively
*/
void BST::DeleteTreeRecursive(Node* node)
{
    if (node == nullptr)
        return;

    if (node->left != nullptr)
        DeleteTreeRecursive(node->left);
    if (node->right != nullptr)
        DeleteTreeRecursive(node->right);

    delete node;
}

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

/**
 * find the node with minimum value of give (sub)tree
 * @param node root of sub(tree)
 * @return node with minimum value
*/
Node* BST::findMinNode(Node* node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

/**
 * returns left-most item present in binary search tree which is also
 * the minimum element in bst
 * @return minimum element present in bst
*/
int BST::min()
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
 * returns right-most item present in binary search tree which is also
 * the maximum element in bst
 * @return maximum element present in bst
*/
int BST::max()
{
    Node* root = getRoot();
    if (root == nullptr)
        throw EmptyTree();

    Node* current = root;
    while (current->right != nullptr)
        current = current->right;

    return current->data;
}

/**
 * height is recursive internal method that works at node-level
 * @return height of tree/sub-tree
*/
int BST::height(Node* root)
{
    if (root == nullptr)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    return rightHeight + 1;
}

/**
 * calculate height of binary search tree
 * @return height of tree
*/
int BST::height()
{
    if (root == nullptr)
        throw EmptyTree();

    return height(root);
}

/**
 * delete first occurance of value from binary search tree
 * @param value node with value to be deleted
*/
void BST::deleteNode(int value)
{
    root = deleteNode(root, value);
}

/**
 * delete is interal recursive method that works at node-level
 * @param root root of (sub)tree
 * @param value node with value to be deleted
 * @return modified root node
*/
Node* BST::deleteNode(Node* root, int value)
{
    if (root == nullptr)
        return root;

    else if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            Node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
