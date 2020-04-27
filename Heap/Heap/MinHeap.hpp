/**
 * Heap Data Strucure - Min Heap (C++ implementation)
 *
 * A Heap is a special Tree-based data structure in which the tree is a
 * complete binary tree.
 * In a Min-Heap the key present at the root node must be minimum among the
 * keys present at all of it’s children. The same property must be
 * recursively true for all sub-trees in that Binary Tree.
 */
#include <algorithm>
#include "HeapException.hpp"

namespace Heap {
    template <typename T>
    class MinHeap {
    private:
        T* data;     // pointer to array of elements in heap
        int size;      // current number of elements in heap
        int capacity;  // maximum possible size of heap

        void swim(int k);
        void sink(int k);
        int parent(int k) { return k / 2; }
        int leftChild(int k) { return 2 * k; }
        int rightChild(int k) { return 2 * k + 1; }

    public:
        MinHeap(int capacity);
        MinHeap(T* array, int arrayLen);
        int getSize();
        bool isFull();
        bool isEmpty();
        void insert(T item);
        T extractMin();
        T min();
    };

    /**
     * swim moves element at index k upward to maintain heap invariant
     * @param k node index that needs to swim up
     */
    template <typename T>
    void MinHeap<T>::swim(int k) {
        if (k <= 1) {
            // k is the root node
            return;
        }
        int p = parent(k);
        if (data[p] > data[k]) {
            std::swap(data[p], data[k]);
            swim(p);
        }
    }

    /**
     * sink moves element at index k downward to maintain heap invariant
     * @param k node index that needs to sink down
     */
    template <typename T>
    void MinHeap<T>::sink(int k) {
        int min = k;

        // find index of minimum value (k, k's left child, k's right child)
        int left = leftChild(k);
        if (left <= size) {
            if (data[min] > data[left]) min = left;
        }

        int right = rightChild(k);
        if (right <= size) {
            if (data[min] > data[right]) min = right;
        }

        if (min != k) {
            std::swap(data[k], data[min]);
            sink(min);
        }
    }

    /**
     * creates new empty 1-indexed heap
     * @param capacity maximum possible size of heap
     */
    template <typename T>
    MinHeap<T>::MinHeap(int capacity) : capacity(capacity) {
        data = new T[capacity + 1];
        size = 0;
    }

    /**
     * builds heap structure from an unorganized array data
     * Time complexity of building a heap is O(n)
     * @param array pointer to array
     * @param arrayLen number of items in array
     */
    template <typename T>
    MinHeap<T>::MinHeap(T* array, int arrayLen) {
        capacity = arrayLen;
        data = new T[capacity + 1];
        size = arrayLen;

        for (int i = 0; i < arrayLen; i++) {
            data[i + 1] = array[i];
        }

        for (int i = arrayLen / 2; i >= 1; i--) {
            sink(i);
        }
    }

    /**
     * checks if heap is full
     * @return true if heap is full, else false
     */
    template <typename T>
    bool MinHeap<T>::isFull() {
        return size >= capacity;
    }

    /**
     * checks if heap is empty
     * @return true if heap is empty, else false
     */
    template <typename T>
    bool MinHeap<T>::isEmpty() {
        return size == 0;
    }

    /**
     * get Heap size
     * @return total number of elements currently present in heap
     */
    template <typename T>
    int MinHeap<T>::getSize() {
        return size;
    }

    /**
     * inserts new element into heap
     * @param item insert item in heap while maintaining the heap property
     * @throw Heap::Exception::FullHeap when trying to insert item in
     *      completely filled heap
     */
    template <typename T>
    void MinHeap<T>::insert(T item) {
        if (isFull())
            throw Exception::FullHeap();

        size = size + 1;
        data[size] = item;
        swim(size);
    }

    /**
     * returns the minimum value (i.e. root) in the heap and
     * removes it from the heap.
     * @return minimum value from heap
     * @throw MinHeap::Exception::EmptyHeap when trying to access item from
     *      empty heap
     */
    template <typename T>
    T MinHeap<T>::extractMin() {
        if (isEmpty())
            throw Exception::EmptyHeap();

        T minValue = data[1];
        data[1] = data[size];
        size = size - 1;
        sink(1);
        return minValue;
    }

    /**
     * returns the minimum value (i.e. root) in the heap, without
     * removing it.
     * @return minimum value from heap
     * @throw MinHeap::Exception::EmptyHeap when trying to access item from
     *      empty heap
     */
    template <typename T>
    T MinHeap<T>::min() {
        if (isEmpty())
            throw Exception::EmptyHeap();

        return data[1];
    }
}