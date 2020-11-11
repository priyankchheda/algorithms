""" Implementation of Shell Sort algorithm
"""


def shell(array):
    """ Shell sort is mainly a variation of Insertion Sort. In insertion sort,
    we move elements only one position ahead. When an element has to be moved
    far ahead, many movements are involved. The idea of shellSort is to allow
    exchange of far items. In shellSort, we make the array h-sorted for a large
    value of h. We keep reducing the value of h until it becomes 1. An array is
    said to be h-sorted if all sublists of every h’th element is sorted.

    :param array: list of elements that needs to be sorted
    :type array: list
    """
    length = len(array)
    gaps = [701, 301, 132, 57, 23, 10, 4, 1]

    for gap in gaps:
        h_gap = gap
        while h_gap < length:
            temp = array[h_gap]
            i = h_gap
            while i >= gap and array[i - gap] > temp:
                array[i] = array[i - gap]
                i -= gap
            array[i] = temp
            h_gap += 1


def main():
    """ operational function """
    arr = [34, 56, 23, 67, 3, 68]
    print(f"unsorted array: {arr}")
    shell(arr)
    print(f"  sorted array: {arr}")


if __name__ == "__main__":
    main()
