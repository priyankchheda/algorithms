/**
 * Depth First Traversal of Binary Search Tree
 * C++ Implementation
 *
 * DFS (Depth-first search) is technique used for traversing tree or graph.
 * Here backtracking is used for traversal. In this traversal first the
 * deepest node is visited and then backtracks to it’s parent node if no
 * sibling of that node exist.
*/

#include <iostream>
#include <vector>
#include "BST/BST.hpp"

void preOrder(Node* node, std::vector<int>& output);
void inOrder(Node* node, std::vector<int>& output);
void postOrder(Node* node, std::vector<int>& output);

int main()
{
    BST tree;
    int original[] = { 9, 5, 3, 10, 6, 1, 7, 4 };
    for (int i : original)
        tree.insert(i);

    Node* root = tree.getRoot();
    std::vector<int> output;

    preOrder(root, output);
    std::cout << " PreOrder: ";
    for (int o: output)
        std::cout << o << " ";
    std::cout << "\n";
    output.clear();

    inOrder(root, output);
    std::cout << "  InOrder: ";
    for (int o: output)
        std::cout << o << " ";
    std::cout << "\n";
    output.clear();

    postOrder(root, output);
    std::cout << "PostOrder: ";
    for (int o: output)
        std::cout << o << " ";
    std::cout << "\n";
    output.clear();
    return 0;
}

/**
 * Pre Order Tree Traversal
 * Visit the root node
 * Visit all the nodes in the left subtree
 * Visit all the nodes in the right subtree
 *
 * @param node root of tree/sub-tree
 * @param output output vector to store order
*/
void preOrder(Node* node, std::vector<int>& output)
{
    if (node == nullptr)
        return;

    output.push_back(node->data);
    preOrder(node->left, output);
    preOrder(node->right, output);
}

/**
 * In Order Tree Traversal
 * Visit all the nodes in the left subtree
 * Visit the root node
 * Visit all the nodes in the right subtree
 *
 * @param node root of tree/sub-tree
 * @param output output vector to store order
*/
void inOrder(Node* node, std::vector<int>& output)
{
    if (node == nullptr)
        return;

    inOrder(node->left, output);
    output.push_back(node->data);
    inOrder(node->right, output);
}

/**
 * Post Order Tree Traversal
 * Visit all the nodes in the left subtree
 * Visit all the nodes in the right subtree
 * Visit the root node
 *
 * @param node root of tree/sub-tree
 * @param output output vector to store order
*/
void postOrder(Node* node, std::vector<int>& output)
{
    if (node == nullptr)
        return;

    postOrder(node->left, output);
    postOrder(node->right, output);
    output.push_back(node->data);
}
