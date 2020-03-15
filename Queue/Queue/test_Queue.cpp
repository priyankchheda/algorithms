#include <gtest/gtest.h>
#include "Queue.hpp"

TEST(QueueEmptyTest, EnqueueTest) {
    Queue queue(5);
    for (int i = 1; i < 5; i++)
        ASSERT_EQ(0, queue.enqueue(i));
    ASSERT_EQ(-1, queue.enqueue(6));
    ASSERT_EQ(-1, queue.enqueue(7));
}
