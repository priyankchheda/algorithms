#include "RedBlackTree.hpp"

void RedBlackTree::leftRotate(Node* node) {
    Node* right = node->right;
    replaceNode(node, right);
    node->right = right->left;
    if (right->left != nullptr)
        right->left->parent = node;
    right->left = node;
    node->parent = right;
}

void RedBlackTree::rightRotate(Node* node) {
    Node* left = node->left;
    replaceNode(node, left);
    node->left = left->right;
    if (left->right != nullptr)
        left->right->parent = node;
    left->right = node;
    node->parent = left;
}

void RedBlackTree::replaceNode(Node* oldNode, Node* newNode) {
    if (oldNode->parent == nullptr) {
        root = newNode;
    } else {
        if (oldNode == oldNode->parent->left)
            oldNode->parent->left = newNode;
        else oldNode->parent->right = newNode;
    }
    if (newNode != nullptr)
        newNode->parent = oldNode->parent;
}