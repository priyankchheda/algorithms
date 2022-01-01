/**
 * LevelOrder traversal of a tree is breadth first traversal for the tree
 *
 * Example:
 *
 *	        F
 *	      /	  \
 *	     B     G
 *	   /   \    \
 *	 A      D    I
 *
 *	Level Order Traversal := F -> B -> G -> A -> D -> I
*/
#include <iostream>
#include <queue>
#include "BST/BST.hpp"

void levelOrder(const BST& tree, std::vector<int>& output);

/* Main Operational Function */
int main()
{
    BST tree;
    int original[] = { 9, 5, 3, 10, 6, 1, 7, 4 };
    for (int i : original)
        tree.insert(i);

    std::vector<int> output;
    levelOrder(tree, output);
    for (int o : output)
        std::cout << o << " ";
    std::cout << "\n";
    return 0;
}

/**
 * Breadth First Traversal (Level Order Traversal)
 * @param tree bst tree object
 * @param output output of level order traversal is stored in vector
*/
void levelOrder(const BST& tree, std::vector<int>& output)
{
    Node* root = tree.getRoot();
    if (root == nullptr)
        return;

    std::queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* node = q.front();
        output.push_back(node->data);
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
        q.pop();
    }
}
