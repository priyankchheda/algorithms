#include <iostream>
#include "RedBlackTree.hpp"

/**
 * Delete red black tree nodes recursively
*/
void RedBlackTree::deleteTreeRecursive(Node* node) {
    if (node == nullptr)
        return;

    if (node->left != nullptr)
        deleteTreeRecursive(node->left);
    if (node->right != nullptr)
        deleteTreeRecursive(node->right);
    delete node;
}

/**
 * returns node color
 * @param node pointer to red black tree node
*/
int RedBlackTree::getNodeColor(Node* node) {
    if (node == nullptr)
        return BLACK;
    return node->color;
}

/**
 * returns uncle of node
 * @param node pointer to red black tree node
*/
Node* RedBlackTree::uncle(Node* node) {
    if (node == nullptr || node->parent == nullptr ||
        node->parent->parent == nullptr)
            return nullptr;

    return sibling(node->parent);
}

/**
 * returns sibling of given node
 * @param node pointer to red black tree node
*/
Node* RedBlackTree::sibling(Node* node) {
    if (node == nullptr || node->parent == nullptr)
        return nullptr;

    if (node == node->parent->left)
        return node->parent->right;
    return node->parent->left;
}

/**
 * returns grandparent of node
 * @param node pointer to red black tree node
*/
Node* RedBlackTree::grandparent(Node* node) {
    if (node == nullptr || node->parent == nullptr)
        return nullptr;
    return node->parent->parent;
}
