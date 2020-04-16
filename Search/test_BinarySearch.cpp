#include <gtest/gtest.h>
#include "BinarySearch.h"

TEST(BinarySearch, EmptyArray)
{
    int arr[] = {};
    ASSERT_EQ(-1, binarySearch<int>(arr, 0, 4));
}

TEST(BinarySearch, SingleElementArray)
{
    int arr[] = {3};
    ASSERT_EQ(-1, binarySearch<int>(arr, 1, 4));
    ASSERT_EQ(0, binarySearch<int>(arr, 1, 3));
}

TEST(BinarySearch, PositiveNumberArray)
{
    int arr[] = {2, 3, 23, 27, 56, 73, 93, 99, 789};
    ASSERT_EQ(-1, binarySearch<int>(arr, 9, 98));
    ASSERT_EQ(3, binarySearch<int>(arr, 9, 27));
}

TEST(BinarySearch, NegativeNumberArray)
{
    int arr[] = {-3, -23, -56, 37, 73, 93, 99};
    ASSERT_EQ(-1, binarySearch<int>(arr, 7, 98));
    ASSERT_EQ(1, binarySearch<int>(arr, 7, -23));
}

TEST(BinarySearchRecursive, EmptyArray)
{
    int arr[] = {};
    ASSERT_EQ(-1, binarySearchRecursive<int>(arr, 0, -1, 4));
}

TEST(BinarySearchRecursive, SingleElementArray)
{
    int arr[] = {3};
    ASSERT_EQ(-1, binarySearchRecursive<int>(arr, 0, 0, 4));
    ASSERT_EQ(0, binarySearchRecursive<int>(arr, 0, 0, 3));
}

TEST(BinarySearchRecursive, PositiveNumberArray)
{
    int arr[] = {2, 3, 23, 27, 56, 73, 93, 99, 789};
    ASSERT_EQ(-1, binarySearchRecursive<int>(arr, 0, 8, 98));
    ASSERT_EQ(3, binarySearchRecursive<int>(arr, 0, 8, 27));
}

TEST(BinarySearchRecursive, NegativeNumberArray)
{
    int arr[] = {-3, -23, -56, 37, 73, 93, 99};
    ASSERT_EQ(-1, binarySearchRecursive<int>(arr, 0, 6, 98));
    ASSERT_EQ(1, binarySearchRecursive<int>(arr, 0, 6, -23));
}