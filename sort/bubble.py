""" Implementation of Bubble Sort algorithm
"""


def bubble(array):
    """ Bubble sort is a simple sorting algorithm that repeatedly steps
    through the list to be sorted, compares each pair of adjacent items and
    swaps them if they are in the wrong order. The pass through the list is
    repeated until no swaps are needed, which indicates that the list is
    sorted.

    :param array: list of elements that needs to be sorted
    :type array: list
    """
    length = len(array)
    swapped = True

    while swapped:
        swapped = False
        for i in range(length - 1):
            if array[i] > array[i+1]:
                array[i], array[i+1] = array[i+1], array[i]
                swapped = True


def main():
    """ operational function """
    arr = [34, 56, 23, 67, 3, 68]
    print(f"unsorted array: {arr}")
    bubble(arr)
    print(f"  sorted array: {arr}")


if __name__ == "__main__":
    main()
