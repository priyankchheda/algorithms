#include <gtest/gtest.h>
#include "BST.hpp"

/* Fixtures */
// Binary Search Tree initial setup
class BSTDataInit : public testing::Test {
protected:
    BST bst;
    std::vector<int> original{ 9, 5, 3, 10, 6, 1, 7, 4 };
    void SetUp() override {
        for (int i : original)
            bst.insert(i);
    }
};

// inorder traversal
void inorder(Node* node, std::vector<int>& output)
{
    if (node == nullptr)
        return;
    inorder(node->left, output);
    output.push_back(node->data);
    inorder(node->right, output);
}

// inorder traversal and storing the output in vector
std::vector<int> inorderVector(BST& tree)
{
    std::vector<int> output;
    inorder(tree.getRoot(), output);
    return output;
}

/* Binary Search Tree Insertion */
// test insert method on empty binary search tree
TEST(BSTEmpty, InsertTest)
{
    BST bst;
    bst.insert(9);
    ASSERT_EQ(9, bst.getRoot()->data);
    bst.insert(5);
    ASSERT_EQ(5, bst.getRoot()->left->data);
    bst.insert(3);
    ASSERT_EQ(3, bst.getRoot()->left->left->data);
    bst.insert(10);
    ASSERT_EQ(10, bst.getRoot()->right->data);
    bst.insert(6);
    ASSERT_EQ(6, bst.getRoot()->left->right->data);
    bst.insert(1);
    ASSERT_EQ(1, bst.getRoot()->left->left->left->data);
    bst.insert(7);
    ASSERT_EQ(7, bst.getRoot()->left->right->right->data);
    bst.insert(4);
    ASSERT_EQ(4, bst.getRoot()->left->left->right->data);
}

// test insert method on filled binary search tree
TEST_F(BSTDataInit, InsertTest)
{
    std::vector<int> output = inorderVector(bst);
    std::sort(original.begin(), original.end());
    ASSERT_TRUE(original == output);
}

/* Binary Search Tree Searching */
// test search method on empty binary search tree
TEST(BSTEmpty, SearchTest)
{
    BST bst;
    ASSERT_FALSE(bst.search(4));
    ASSERT_FALSE(bst.search(-1));
    ASSERT_FALSE(bst.search(1));
}

// test search method on filled binary search tree
TEST_F(BSTDataInit, SearchTest)
{
    ASSERT_TRUE(bst.search(9));
    ASSERT_TRUE(bst.search(10));
    ASSERT_TRUE(bst.search(1));
    ASSERT_TRUE(bst.search(6));
    ASSERT_FALSE(bst.search(2));
    ASSERT_FALSE(bst.search(-1));
    ASSERT_FALSE(bst.search(20));
    ASSERT_FALSE(bst.search(12));
}

// test min method on empty binary search tree
TEST(BSTEmpty, findMinTest)
{
    BST bst;
    ASSERT_THROW(bst.min(), EmptyTree);
    bst.insert(5);
    ASSERT_EQ(5, bst.min());
    bst.insert(9);
    ASSERT_EQ(5, bst.min());
    bst.insert(3);
    ASSERT_EQ(3, bst.min());
}

// test min method on filled binary search tree
TEST_F(BSTDataInit, findMinTest)
{
    ASSERT_EQ(1, bst.min());
}

// test max method on empty binary search tree
TEST(BSTEmpty, findMaxTest)
{
    BST bst;
    ASSERT_THROW(bst.max(), EmptyTree);
    bst.insert(5);
    ASSERT_EQ(5, bst.max());
    bst.insert(9);
    ASSERT_EQ(9, bst.max());
    bst.insert(3);
    ASSERT_EQ(9, bst.max());
}

// test max method on filled binary search tree
TEST_F(BSTDataInit, findMaxTest)
{
    ASSERT_EQ(10, bst.max());
}

// test height on empty binary search tree
TEST(BSTEmpty, heightTest)
{
    BST bst;
    ASSERT_THROW(bst.height(), EmptyTree);
    bst.insert(5);
    ASSERT_EQ(0, bst.height());
    bst.insert(6);
    ASSERT_EQ(1, bst.height());
    bst.insert(7);
    ASSERT_EQ(2, bst.height());
    bst.insert(4);
    ASSERT_EQ(2, bst.height());
    bst.insert(3);
    ASSERT_EQ(2, bst.height());
    bst.insert(8);
    ASSERT_EQ(3, bst.height());
}

// test height on filled binary search tree
TEST_F(BSTDataInit, heightTest)
{
    ASSERT_EQ(3, bst.height());
}

// test delete node method on empty search tree
TEST(BSTEmpty, deleteNodeTest)
{
    BST bst;
    bst.deleteNode(5);
    ASSERT_EQ(nullptr, bst.getRoot());
}

// test delete node method on filled search tree
TEST_F(BSTDataInit, deleteNodeTest)
{
    bst.deleteNode(3);
    ASSERT_EQ(5, bst.getRoot()->left->data);
    ASSERT_EQ(4, bst.getRoot()->left->left->data);
    ASSERT_EQ(nullptr, bst.getRoot()->left->left->right);
    ASSERT_EQ(1, bst.getRoot()->left->left->left->data);

    bst.deleteNode(5);
    Node* root = bst.getRoot();
    ASSERT_EQ(9, root->data);
    ASSERT_EQ(6, root->left->data);
    ASSERT_EQ(10, root->right->data);
    ASSERT_EQ(4, root->left->left->data);
    ASSERT_EQ(1, root->left->left->left->data);
    ASSERT_EQ(7, root->left->right->data);

}
