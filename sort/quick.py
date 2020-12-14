""" Implementation of Quick Sort algorithm
"""


def partition(data, low, high):
    """ partition return partition index of pivot

    :param array: list of elements that needs to be sorted
    :param low: lower index of sub-array
    :param high: higher index of sub-array
    :returns: partition index of pivot
    """
    pivot = data[high]
    partition_index = low
    for i in range(low, high):
        if data[i] <= pivot:
            data[i], data[partition_index] = data[partition_index], data[i]
            partition_index += 1

    data[high], data[partition_index] = data[partition_index], data[high]
    return partition_index


def quick(data, low, high):
    """ QuickSort is a Divide and Conquer algorithm.
    It picks an element as pivot and partitions the given array around the
    picked pivot. It uses last element as pivot element

    :param array: list of elements that needs to be sorted
    :param low: lower index of sub-array
    :param high: higher index of sub-array
    """
    if high <= low:
        return
    j = partition(data, low, high)
    quick(data, low, j-1)
    quick(data, j+1, high)


def main():
    """ operational function """
    arr = [34, 56, 23, 67, 3, 68]
    print(f"unsorted array: {arr}")
    quick(arr, 0, len(arr)-1)
    print(f"  sorted array: {arr}")


if __name__ == "__main__":
    main()
