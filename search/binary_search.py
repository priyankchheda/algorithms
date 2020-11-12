""" Implementation of Binary Search algorithm """


def binary_search_iterative(array, item):
    """ Iterative version of Binary search
    Returns index if the item is found in the list, else returns None
    """
    start = 0
    end = len(array) - 1

    while start <= end:
        median = (start + end) // 2
        if array[median] == item:
            return median
        if array[median] < item:
            start = median + 1
        else:
            end = median - 1
    return None


def binary_search_recursive(array, start, end, item):
    """ Recursive version of binary search algorithm
    Returns index if the item is found in the list, else returns None
    """
    if end >= start:
        median = (start + end) // 2
        if array[median] == item:
            return median
        if array[median] < item:
            return binary_search_recursive(array, median+1, end, item)
        return binary_search_recursive(array, start, median-1, item)
    return None


def main():
    """ operational function """
    array = [34, 36, 46, 48, 67, 68, 69, 71, 73, 97]
    print(binary_search_iterative(array, 34))
    print(binary_search_recursive(array, 0, len(array)-1, 97))


if __name__ == "__main__":
    main()
