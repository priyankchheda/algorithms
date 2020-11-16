""" Implementation of Odd-Even Sort algorithm
"""


def oddeven(data):
    """ OddEvenSort is a variation of bubble sort where the sorting is divided
    into two phases, Odd and Even Phase and it runs until all the elements
    are sorted. In the odd phase we perform bubble sort on odd indexed
    elements and in the even phase we perform bubble sort on even indexed
    elements.

    :param array: list of elements that needs to be sorted
    :type array: list
    """
    is_sorted = False
    data_len = len(data)

    while not is_sorted:
        is_sorted = True
        for i in range(1, data_len-1, 2):
            if data[i] > data[i+1]:
                data[i], data[i+1] = data[i+1], data[i]
                is_sorted = False

        for i in range(0, data_len-1, 2):
            if data[i] > data[i+1]:
                data[i], data[i+1] = data[i+1], data[i]
                is_sorted = False


def main():
    """ operational function """
    arr = [34, 56, 23, 67, 3, 68]
    print(f"unsorted array: {arr}")
    oddeven(arr)
    print(f"  sorted array: {arr}")


if __name__ == "__main__":
    main()
