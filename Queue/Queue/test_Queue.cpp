#include <gtest/gtest.h>
#include "Queue.hpp"

/* Fixtures */
// generating completely full queue
class QueueTest : public testing::Test {
protected:
	Queue queue;
	QueueTest(): queue(5) {}
	void SetUp() override {
		for (int i = 1; i < 6; i++)
			queue.enqueue(i);
	}
};

// test queue.enqueue method
TEST(QueueEmptyTest, EnqueueTest) {
    Queue queue(5);
    for (int i = 1; i < 6; i++)
        ASSERT_EQ(0, queue.enqueue(i));
    ASSERT_EQ(-1, queue.enqueue(6));
    ASSERT_EQ(1, queue.dequeue());
    ASSERT_EQ(0, queue.enqueue(7));
    ASSERT_EQ(2, queue.dequeue());
    ASSERT_EQ(0, queue.enqueue(8));
    ASSERT_EQ(-1, queue.enqueue(9));
}

// test queue.isEmpty method
TEST(QueueEmptyTest, isEmptyTest) {
    Queue queue(5);
    ASSERT_TRUE(queue.isEmpty());
    ASSERT_EQ(0, queue.enqueue(1));
    ASSERT_FALSE(queue.isEmpty());
    ASSERT_EQ(1, queue.dequeue());
    ASSERT_TRUE(queue.isEmpty());
}

// test queue.dequeue method
TEST_F(QueueTest, DequeueTest) {
    for (int i = 1; i < 6; i++) {
        ASSERT_EQ(i, queue.dequeue());
    }
    ASSERT_EQ(-2, queue.dequeue());
    ASSERT_EQ(0, queue.enqueue(67));
    ASSERT_EQ(67, queue.dequeue());
    ASSERT_EQ(-2, queue.dequeue());

}

// test queue.peek method
TEST_F(QueueTest, PeekTest) {
    ASSERT_EQ(1, queue.peek());
    ASSERT_EQ(1, queue.peek());
    for (int i = 1; i < 6; i++) {
        ASSERT_EQ(i, queue.peek());
        ASSERT_EQ(i, queue.dequeue());
    }
    ASSERT_EQ(-2, queue.peek());
}

// test queue.isFull method
TEST_F(QueueTest, isFullTest) {
    ASSERT_TRUE(queue.isFull());
    ASSERT_EQ(1, queue.dequeue());
    ASSERT_FALSE(queue.isFull());
    ASSERT_EQ(0, queue.enqueue(5));
    ASSERT_TRUE(queue.isFull());
}

// test queue.size method
TEST_F(QueueTest, sizeTest) {
    ASSERT_EQ(5, queue.size());
    queue.enqueue(6);
    ASSERT_EQ(5, queue.size());
    queue.dequeue();
    queue.dequeue();
    ASSERT_EQ(3, queue.size());
    queue.enqueue(6);
    ASSERT_EQ(4, queue.size());
    ASSERT_EQ(3, queue.dequeue());
    ASSERT_EQ(3, queue.size());
}