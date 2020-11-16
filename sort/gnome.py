""" Implementation of Gnome Sort algorithm
"""


def gnome(data):
    """ GnomeSort is a sorting algorithm which is similar
    to insertion sort in that it works with one item at a time
    but gets the item to the proper place by a series of swaps.

    :param array: list of elements that needs to be sorted
    :type array: list
    """
    index = 0
    data_len = len(data)
    while index < data_len:
        if index == 0 or data[index] >= data[index - 1]:
            index = index + 1
        else:
            data[index], data[index-1] = data[index-1], data[index]
            index = index - 1


def main():
    """ operational function """
    arr = [34, 56, 23, 67, 3, 68]
    print(f"unsorted array: {arr}")
    gnome(arr)
    print(f"  sorted array: {arr}")


if __name__ == "__main__":
    main()
