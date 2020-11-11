""" Implementation of Selection Sort algorithm
"""


def selection(array):
    """ Selection sort algorithm sorts an array by repeatedly finding the
    minimum element (considering ascending order) from unsorted part and
    putting it at the beginning.

    :param array: list of elements that needs to be sorted
    :type array: list
    """
    length = len(array)
    for i in range(length - 1):
        min_element_index = i
        for j in range(i+1, length):
            if array[j] < array[min_element_index]:
                min_element_index = j
        array[i], array[min_element_index] = array[min_element_index], array[i]


def main():
    """ operational function """
    arr = [34, 56, 23, 67, 3, 68]
    print(f"unsorted array: {arr}")
    selection(arr)
    print(f"  sorted array: {arr}")


if __name__ == "__main__":
    main()
