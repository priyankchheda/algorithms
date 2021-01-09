#include <iostream>
#include <gtest/gtest.h>

#include "MaxHeap.hpp"
#include "MinHeap.hpp"

TEST(MaxHeap, InsertTest) {
    Heap::MaxHeap<float> maxheap(5);
    ASSERT_TRUE(maxheap.isEmpty());
    ASSERT_EQ(0, maxheap.getSize());
    maxheap.insert(5.3f);
    ASSERT_FALSE(maxheap.isEmpty());
    maxheap.insert(10.4f);
    maxheap.insert(3.24f);
    ASSERT_EQ(3, maxheap.getSize());
    maxheap.insert(1.1f);
    maxheap.insert(7.9f);
    ASSERT_EQ(5, maxheap.getSize());
    ASSERT_TRUE(maxheap.isFull());
    ASSERT_THROW(maxheap.insert(11.0), Heap::Exception::FullHeap);
}

TEST(MaxHeap, getSizeTest) {
    Heap::MaxHeap<int> maxheap(5);
    ASSERT_TRUE(maxheap.isEmpty());
    ASSERT_EQ(0, maxheap.getSize());
    for (int i = 1; i < 6; i++) {
        maxheap.insert(i);
        ASSERT_EQ(i, maxheap.getSize());
    }
    ASSERT_TRUE(maxheap.isFull());
    ASSERT_EQ(5, maxheap.getSize());
}

TEST(MaxHeap, MaxTest) {
    Heap::MaxHeap<char> maxheap(5);
    ASSERT_THROW(maxheap.max(), Heap::Exception::EmptyHeap);
    maxheap.insert('e');
    ASSERT_EQ('e', maxheap.max());
    maxheap.insert('c');
    ASSERT_EQ('e', maxheap.max());
    maxheap.insert('f');
    ASSERT_EQ('f', maxheap.max());
    maxheap.insert('x');
    ASSERT_EQ('x', maxheap.max());
    maxheap.insert('t');
    ASSERT_EQ('x', maxheap.max());
}

TEST(MaxHeap, ExtractMaxTest) {
    Heap::MaxHeap<int> maxheap(5);
    ASSERT_THROW(maxheap.extractMax(), Heap::Exception::EmptyHeap);
    maxheap.insert(5);
    maxheap.insert(1);
    maxheap.insert(3);
    maxheap.insert(2);
    maxheap.insert(4);
    for (int i = 5; i > 0; i--)
        ASSERT_EQ(i, maxheap.extractMax());
}

TEST(MaxHeap, BuildHeapTest) {
    int arr[] = {4, 7, 2, 8, 1, 5, 3, 6, 9};
    Heap::MaxHeap<int> maxheap(arr, 9);
    for (int i = 9; i > 0; i--) {
        ASSERT_EQ(i, maxheap.extractMax());
    }
}

TEST(MinHeap, InsertTest) {
    Heap::MinHeap<float> minheap(5);
    ASSERT_TRUE(minheap.isEmpty());
    ASSERT_EQ(0, minheap.getSize());
    minheap.insert(5.3f);
    ASSERT_FALSE(minheap.isEmpty());
    minheap.insert(10.4f);
    minheap.insert(3.24f);
    ASSERT_EQ(3, minheap.getSize());
    minheap.insert(1.1f);
    minheap.insert(7.9f);
    ASSERT_EQ(5, minheap.getSize());
    ASSERT_TRUE(minheap.isFull());
    ASSERT_THROW(minheap.insert(11.0), Heap::Exception::FullHeap);
}

TEST(MinHeap, getSizeTest) {
    Heap::MinHeap<int> minheap(5);
    ASSERT_TRUE(minheap.isEmpty());
    ASSERT_EQ(0, minheap.getSize());
    for (int i = 1; i < 6; i++) {
        minheap.insert(i);
        ASSERT_EQ(i, minheap.getSize());
    }
    ASSERT_TRUE(minheap.isFull());
    ASSERT_EQ(5, minheap.getSize());
}

TEST(MinHeap, MinTest) {
    Heap::MinHeap<char> minheap(5);
    ASSERT_THROW(minheap.min(), Heap::Exception::EmptyHeap);
    minheap.insert('f');
    ASSERT_EQ('f', minheap.min());
    minheap.insert('x');
    ASSERT_EQ('f', minheap.min());
    minheap.insert('e');
    ASSERT_EQ('e', minheap.min());
    minheap.insert('c');
    ASSERT_EQ('c', minheap.min());
    minheap.insert('t');
    ASSERT_EQ('c', minheap.min());
}

TEST(MinHeap, ExtractMinTest) {
    Heap::MinHeap<int> minheap(5);
    ASSERT_THROW(minheap.extractMin(), Heap::Exception::EmptyHeap);
    minheap.insert(5);
    minheap.insert(1);
    minheap.insert(3);
    minheap.insert(2);
    minheap.insert(4);
    for (int i = 1; i < 6; i++)
        ASSERT_EQ(i, minheap.extractMin());
}

TEST(MinHeap, BuildHeapTest) {
    int arr[] = {4, 7, 2, 8, 1, 5, 3, 6, 9};
    Heap::MinHeap<int> minheap(arr, 9);
    for (int i = 1; i < 10; i++) {
        ASSERT_EQ(i, minheap.extractMin());
    }
}