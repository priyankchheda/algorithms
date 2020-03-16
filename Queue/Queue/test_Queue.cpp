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
