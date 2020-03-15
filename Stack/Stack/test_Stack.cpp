#include <gtest/gtest.h>
#include "Stack.hpp"

/* Fixtures */
// generating completely full stack
class StackTest : public testing::Test {
protected:
	Stack stack;
	StackTest(): stack(5) {}
	void SetUp() override {
		for (int i = 1; i < 6; i++)
			stack.push(i);
	}
};

// test stack.isEmpty method
TEST(StackEmptyTest, isEmptyTest) {
    Stack stack(5);
    ASSERT_TRUE(stack.isEmpty());
    ASSERT_EQ(0, stack.push(7));
    ASSERT_FALSE(stack.isEmpty());
    ASSERT_EQ(7, stack.pop());
    ASSERT_TRUE(stack.isEmpty());
}

// test stack.push method
TEST(StackEmptyTest, PushTest) {
    Stack stack(5);
    for (int i = 1; i < 6; i++)
        ASSERT_EQ(0, stack.push(i));
    ASSERT_EQ(-1, stack.push(6));
	ASSERT_EQ(5, stack.pop());
    ASSERT_EQ(0, stack.push(7));
    ASSERT_EQ(-1, stack.push(8));
}

// test stack.pop method
TEST_F(StackTest, PopTest) {
	for (int i = 5; i > 0; i--)
		ASSERT_EQ(i, stack.pop());
    ASSERT_EQ(-2, stack.pop());
    ASSERT_EQ(-2, stack.pop());
}

// test stack.peek method
TEST_F(StackTest, PeekTest) {
    ASSERT_EQ(5, stack.peek());
    ASSERT_EQ(5, stack.peek());
    for (int i = 5; i > 0; i--) {
        ASSERT_EQ(i, stack.peek());
        ASSERT_EQ(i, stack.pop());
    }
    ASSERT_EQ(-2, stack.pop());
    ASSERT_EQ(-2, stack.pop());
}

// test stack.isFull method
TEST_F(StackTest, isFullTest) {
    ASSERT_TRUE(stack.isFull());
    ASSERT_EQ(5, stack.pop());
    ASSERT_FALSE(stack.isFull());
    ASSERT_EQ(0, stack.push(5));
    ASSERT_TRUE(stack.isFull());
}

// test stack.size method
TEST_F(StackTest, sizeTest) {
    ASSERT_EQ(5, stack.size());
    stack.push(6);
    ASSERT_EQ(5, stack.size());
    stack.pop();
    stack.pop();
    ASSERT_EQ(3, stack.size());
    stack.push(6);
    ASSERT_EQ(4, stack.size());
    ASSERT_EQ(6, stack.pop());
    ASSERT_EQ(3, stack.size());

    for (int i = 3; i > 0; i--) {
        ASSERT_EQ(i, stack.size());
        ASSERT_EQ(i, stack.pop());
    }

    ASSERT_TRUE(stack.isEmpty());
}
