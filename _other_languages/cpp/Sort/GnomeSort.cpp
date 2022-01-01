/*
 * Sorting Algorithms
 * Gnome Sort (C++ implementation)
 *
 * GnomeSort is a sorting algorithm which is similar
 * to insertion sort in that it works with one item at a time
 * but gets the item to the proper place by a series of swaps.
 */

#include <iostream>
#include <algorithm>

/* Function declaration */
template <typename T>
void GnomeSort(T data[], int dataLen);

/* Main Driver Function */
int main() {
    int arr[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    GnomeSort<int>(arr, arr_size);

    for (int a: arr)
        std::cout << a << " ";
    std::cout << "\n";

    return 0;
}

/**
 * Gnome Sort Template Function
 * @param data actual array to sort
 * @param dataLen size of array
 */
template <typename T>
void GnomeSort(T data[], int dataLen) {
    int index = 0;
    while (index < dataLen) {
        if (index == 0 || data[index] >= data[index - 1]) {
            index++;
        } else {
            std::swap(data[index], data[index - 1]);
            index--;
        }
    }
}