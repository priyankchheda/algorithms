#ifndef HEAP_EXCEPTION_H
#define HEAP_EXCEPTION_H

#include <exception>

namespace Heap {
    namespace Exception {
        /**
         * EmptyHeap exception is raised when you are trying to access
         * element from empty heap.
         */
        class EmptyHeap : public std::exception {
            const char* what() const throw() { return "heap is empty"; }
        };

        /**
         * FullHeap expection is raised when you are trying to insert
         * element in completely filled heap
         */
        class FullHeap : public std::exception {
            const char* what() const throw() { return "heap is full"; }
        };
    }
}

#endif
