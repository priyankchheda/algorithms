/**
 * In Binary Tree, Inorder successor of a node is the next node in Inorder
 * traversal of the Binary Tree. Inorder Successor is NULL for the last node
 * in Inoorder traversal.
 * In Binary Search Tree, Inorder Successor of an input node can also be
 * defined as the node with the smallest key greater than the key of input
 * node. So, it is sometimes important to find next node in sorted order.
*/
#include <iostream>
#include "BST/BST.hpp"

/* Functional Declaration */
Node* inorderSuccessor(BST& tree, int value);
Node* findMinNode(Node* node);

/* Main Operational Function */
int main()
{
    BST tree;
    int original[] = { 9, 5, 3, 10, 6, 1, 7, 4 };
    for (int i : original)
        tree.insert(i);

    std::cout << "inorder successor of 1: " << inorderSuccessor(tree, 1)->data << "\n";
    std::cout << "inorder successor of 2: ";
    if (inorderSuccessor(tree, 2) == nullptr) std::cout << "nullptr\n";
    else std::cout << "not nullptr\n";
    std::cout << "inorder successor of 3: " << inorderSuccessor(tree, 3)->data << "\n";
    std::cout << "inorder successor of 4: " << inorderSuccessor(tree, 4)->data << "\n";
    std::cout << "inorder successor of 5: " << inorderSuccessor(tree, 5)->data << "\n";
    std::cout << "inorder successor of 6: " << inorderSuccessor(tree, 6)->data << "\n";
    std::cout << "inorder successor of 7: " << inorderSuccessor(tree, 7)->data << "\n";
    std::cout << "inorder successor of 8: ";
    if (inorderSuccessor(tree, 8) == nullptr) std::cout << "nullptr\n";
    else std::cout << "not nullptr\n";
    std::cout << "inorder successor of 9: " << inorderSuccessor(tree, 9)->data << "\n";
    std::cout << "inorder successor of 10: ";
    if (inorderSuccessor(tree, 10) == nullptr) std::cout << "nullptr\n";
    else std::cout << "not nullptr\n";
    return 0;
}

/**
 * find the node with minimum value of give (sub)tree
 * @param node root of sub(tree)
 * @return node with minimum value
*/
Node* findMinNode(Node* node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

/**
 * get inorder successor for given value in binary search tree
 * @param value input value of which inorder successor is required
 * @return inorder successor of given value
*/
Node* inorderSuccessor(BST& tree, int value)
{
    Node* current = tree.getRoot();

    while (current != nullptr && current->data != value) {
        if (current->data > value)
            current = current->left;
        else if (current->data < value)
            current = current->right;
    }
    if (current == nullptr)
        return nullptr;

    if (current->right != nullptr) {
        return findMinNode(current->right);
    } else {
        Node* successor = nullptr;
        Node* ancestor = tree.getRoot();
        while(ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}
