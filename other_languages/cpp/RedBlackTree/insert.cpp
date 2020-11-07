#include "RedBlackTree.hpp"

/**
 * inserts new integer data into the tree at the position, so that
 * the red black tree property is maintained.
 * @param data new integer data to be inserted
*/
void RedBlackTree::insert(int data) {
    Node* insertedNode = nullptr;
    if (root == nullptr) {
        root = new Node(data, RED);
        insertedNode = root;
    } else {
        Node* node = root;
        while (true) {
            if (data < node->data) {
                if (node->left == nullptr) {
                    node->left = new Node(data, RED);
                    insertedNode = node->left;
                    break;
                } else {
                    node = node->left;
                }
            } else if (data > node->data) {
                if (node->right == nullptr) {
                    node->right = new Node(data, RED);
                    insertedNode = node->right;
                    break;
                } else {
                    node = node->right;
                }
            } else {
                node->data = data;
                return;
            }
        }
        insertedNode->parent = node;
    }
    insertCase1(insertedNode);
    size++;
}

void RedBlackTree::insertCase1(Node* node) {
    if (node->parent == nullptr) {
        node->color = BLACK;
    } else {
        insertCase2(node);
    }
}

void RedBlackTree::insertCase2(Node* node) {
    if (getNodeColor(node->parent) == BLACK) return;
    insertCase3(node);
}

void RedBlackTree::insertCase3(Node* node) {
    Node* uncleNode = uncle(node);
    if (getNodeColor(uncleNode) == RED) {
        node->parent->color = BLACK;
        uncleNode->color = BLACK;
        grandparent(node)->color = RED;
        insertCase1(grandparent(node));
    } else {
        insertCase4(node);
    }
}

void RedBlackTree::insertCase4(Node* node) {
    Node* grandparentNode = grandparent(node);
    if (node == node->parent->right && node->parent == grandparentNode->left) {
        leftRotate(node->parent);
        node = node->left;
    } else if (node == node->parent->left &&
               node->parent == grandparentNode->right) {
        rightRotate(node->parent);
        node = node->right;
    }
    insertCase5(node);
}

void RedBlackTree::insertCase5(Node* node) {
    node->parent->color = BLACK;
    Node* grandparentNode = grandparent(node);
    grandparentNode->color = RED;
    if (node == node->parent->left && node->parent == grandparentNode->left) {
        rightRotate(grandparentNode);
    } else if (node == node->parent->right &&
               node->parent == grandparentNode->right) {
        leftRotate(grandparentNode);
    }
}