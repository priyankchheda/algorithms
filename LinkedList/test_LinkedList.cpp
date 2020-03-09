#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "LinkedList.hpp"

int getTailData(Node* node) {
    while (node->next != nullptr) {
        node = node->next;
    }
    return node->data;
}

std::vector<int> convertLinkedListToVector(Node* head) {
    std::vector<int> result;
    Node* temp = head;
    while(temp) {
        result.push_back(temp->data);
        temp = temp->next;
    }
    return result;
}

// test insertHead method on empty linked list
TEST(LinkedListEmptyInit, InsertHeadTest) {
    LinkedList ll;
    ll.insertHead(1);
    ASSERT_EQ(1, ll.getHead()->data);
    ll.insertHead(2);
    ASSERT_EQ(2, ll.getHead()->data);
    ll.insertHead(3);
    ASSERT_EQ(3, ll.getHead()->data);
}

// test insertEnd method on empty linked list
TEST(LinkedListEmptyInit, InsertEndTest) {
    LinkedList ll;
    ll.insertEnd(1);
    ASSERT_EQ(1, ll.getHead()->data);
    ll.insertEnd(2);
    ASSERT_EQ(1, ll.getHead()->data);
    ll.insertEnd(3);
    ASSERT_EQ(3, getTailData(ll.getHead()));
    ll.insertEnd(4);
    ASSERT_EQ(4, getTailData(ll.getHead()));
}

// test insertAt method on empty linked list
TEST(LinkedListEmptyInit, InsertAtTest) {
    LinkedList ll;
    ll.insertAt(4, 3);
    ll.insertAt(2, 1);
    ll.insertAt(5, 3);
    ll.insertAt(1, 5);
    ll.insertAt(3, 2);

    int expectedOutput[] = {2, 3, 4, 5, 1};
    std::vector<int> ll_vector = convertLinkedListToVector(ll.getHead());

    for (int i = 0; i < 5; i++)
        ASSERT_EQ(expectedOutput[i], ll_vector[i]);
}

// test getLength method on empty linked list
TEST(LinkedListEmptyInit, GetLengthTest) {
    LinkedList ll;
    ASSERT_EQ(0, ll.getLength());
    ll.insertAt(4, 3);
    ASSERT_EQ(1, ll.getLength());
    ll.insertAt(2, 1);
    ASSERT_EQ(2, ll.getLength());
    ll.insertAt(5, 3);
    ASSERT_EQ(3, ll.getLength());
    ll.insertAt(1, 5);
    ASSERT_EQ(4, ll.getLength());
    ll.insertAt(3, 2);
    ASSERT_EQ(5, ll.getLength());
}

class LinkedListDataInit : public testing::Test {
protected:
    LinkedList ll;
    void SetUp() override {
        ll.insertEnd(1);
        ll.insertEnd(2);
        ll.insertEnd(3);
        ll.insertEnd(4);
        ll.insertEnd(5);
    }
};

TEST_F(LinkedListDataInit, InsertHeadTest) {
    ll.insertHead(6);
    ll.insertHead(7);

    int expectedOutput[] = {7, 6, 1, 2, 3, 4, 5};
    std::vector<int> ll_vector = convertLinkedListToVector(ll.getHead());

    for (int i = 0; i < 7; i++)
        ASSERT_EQ(expectedOutput[i], ll_vector[i]);
}

TEST_F(LinkedListDataInit, InsertEndTest) {
    ll.insertEnd(6);
    ll.insertEnd(7);

    int expectedOutput[] = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> ll_vector = convertLinkedListToVector(ll.getHead());

    for (int i = 0; i < 7; i++)
        ASSERT_EQ(expectedOutput[i], ll_vector[i]);
}

TEST_F(LinkedListDataInit, GetLengthTest) {
    ASSERT_EQ(5, ll.getLength());
    ll.insertAt(5, 3);
    ASSERT_EQ(6, ll.getLength());
}

TEST_F(LinkedListDataInit, InsertAtTest) {
    ll.insertAt(6, 3);
    ll.insertAt(7, 0);
    ll.insertAt(8, 10);
    int expectedOutput[] = {7, 1, 2, 6, 3, 4, 5, 8};
    std::vector<int> ll_vector = convertLinkedListToVector(ll.getHead());

    for (int i = 0; i < 8; i++)
        ASSERT_EQ(expectedOutput[i], ll_vector[i]);
}
