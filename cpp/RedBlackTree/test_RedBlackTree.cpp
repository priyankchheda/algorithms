#include <gtest/gtest.h>
#include "RedBlackTree.hpp"
#include <vector>

/* Fixtures */
// Red Black Tree initial setup
class RBDataInit : public testing::Test {
protected:
    RedBlackTree rb;
    std::vector<int> original{ 19, 5, 1, 18, 3, 8, 24, 13, 16, 12 };
    void SetUp() override {
        for (int i : original)
            rb.insert(i);
    }
};

/* Red Black Tree Insertion */
// test insert method on red black tree
TEST_F(RBDataInit, InsertSizeTest) {
    ASSERT_EQ(10, rb.getSize());
}

/* Red Black Tree Find */
// test find method on red black tree
TEST_F(RBDataInit, FindTest) {
    ASSERT_TRUE(rb.find(5));
    // ASSERT_FALSE(rb.find(2));
}
