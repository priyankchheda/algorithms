""" Implementation of Merge Sort algorithm
"""


def merge(data):
    """ MergeSort is a Divide and Conquer algorithm. It divides input array
    in two halves, calls itself for the two halves and then merges the
    two sorted halves.

    :param array: list of elements that needs to be sorted
    :type array: list
    """
    if len(data) > 1:
        mid = len(data) // 2
        lefthalf = data[:mid]
        righthalf = data[mid:]

        merge(lefthalf)
        merge(righthalf)

        i = j = k = 0
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                data[k] = lefthalf[i]
                i = i + 1
            else:
                data[k] = righthalf[j]
                j = j + 1
            k = k + 1

        while i < len(lefthalf):
            data[k] = lefthalf[i]
            i = i + 1
            k = k + 1

        while j < len(righthalf):
            data[k] = righthalf[j]
            j = j + 1
            k = k + 1


def main():
    """ operational function """
    arr = [34, 56, 23, 67, 3, 68]
    print(f"unsorted array: {arr}")
    merge(arr)
    print(f"  sorted array: {arr}")


if __name__ == "__main__":
    main()
