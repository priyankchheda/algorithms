"""
Shuffle randomize a given array. Here shuffle means that every permutation
of array element shoudl equally likely.
It uses Fisher-Yates (Knuth) shuffling algorithm.

e.g. shuffle a deck of cards

Fisher–Yates shuffle Algorithm works in O(n) time complexity.
The assumption here is, we are given a function rand() that generates
random number in O(1) time.
"""

import random


def shuffle(array):
    """ Fisher–Yates Shuffle Algorithm """
    for i, _ in enumerate(array):
        r_int = random.randint(0, i+1)
        array[i], array[r_int] = array[r_int], array[i]


def main():
    """ operational function """
    array = [34, 36, 46, 48, 67, 68, 69, 71, 73, 97]
    shuffle(array)
    print(array)


if __name__ == "__main__":
    main()
