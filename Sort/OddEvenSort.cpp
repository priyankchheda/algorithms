/*
 * Sorting Algorithms
 * OddEven Sort (C++ implementation)
 *
 * OddEvenSort is a variation of bubble sort where the sorting is divided into
 * two phases, Odd and Even Phase and it runs until all the elements are sorted
 * In the odd phase we perform bubble sort on odd indexed elements and in the
 * even phase we perform bubble sort on even indexed elements.
 */

#include <iostream>

/* Function Declarations */
template <typename T>
void OddEvenSort(T data[], int dataLen);

/* Main Driver Function */
int main() {
    int arr[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    OddEvenSort<int>(arr, arr_size);

    for (int a: arr)
        std::cout << a << " ";
    std::cout << "\n";

    return 0;
}

/**
 * Odd Even Sort Template Function
 * @param data actual array to sort
 * @param dataLen size of array
 */
template <typename T>
void OddEvenSort(T data[], int dataLen) {
    bool sorted = false;

    while (true) {
        sorted = true;
        for (int i = 1; i < dataLen-1; i += 2) {
            if (data[i] > data[i+1]) {
                std::swap(data[i], data[i+1]);
                sorted = false;
            }
        }
        for (int i = 0; i < dataLen-1; i += 2) {
            if (data[i] > data[i+1]) {
                std::swap(data[i], data[i+1]);
                sorted = false;
            }
        }
        if (sorted) {
            break;
        }
    }
}