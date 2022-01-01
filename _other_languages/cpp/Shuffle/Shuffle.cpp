/*
 * Shuffling Algorithms (C++ implementation)
 *
 * Shuffle randomize a given array. Here shuffle means that every permutation
 * of array element should equally likely.
 * It uses Fisher-Yates (Knuth) shuffling algorithm.
 *
 * e.g. shuffle a deck of cards
 *
 * Fisher–Yates shuffle Algorithm works in O(n) time complexity.
 * The assumption here is, we are given a function rand() that generates
 * random number in O(1) time.
 */

#include <iostream>

/**
 * Shuffle Array Template Function
 * @param arr actual array to sort
 * @param len size of array
 */
template <typename T>
void Shuffle(T arr[], int len)
{
     // use current time as seed for random generator
    std::srand(std::time(nullptr));
    for (int i = 0; i < len; i++) {
        int r = rand() % (i + 1);
        std::swap(arr[i], arr[r]);
    }
}

/* Main Driver Function */
int main()
{
    int arr[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    int len = sizeof(arr) / sizeof(arr[0]);

    Shuffle<int>(arr, len);

    for (int a: arr)
        std::cout << a << " ";
    std::cout << "\n";

    return 0;
}