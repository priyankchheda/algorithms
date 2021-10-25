""" Maximum and minimum of an array using minimum number of comparisons

    Tournament Method and pair comparison approaches make the equal number of comparisons
    when n is a power of 2.
    In general, pair comparison seems to be the best.
"""

def getminmax_linear_search(arr):
    """ Linear method
        Initialize values of min and max as minimum and maximum of the first two elements
        respectively. Starting from 3rd, compare each element with max and min, and
        change max and min accordingly
    """
    if len(arr) == 0:
        return None, None

    if len(arr) == 1:
        return arr[0], arr[0]

    min_num = None
    max_num = None
    if arr[0] > arr[1]:
        max_num = arr[0]
        min_num = arr[1]
    else:
        max_num = arr[1]
        min_num = arr[0]

    for idx in range(2, len(arr)):
        if min_num > arr[idx]:
            min_num = arr[idx]
        if max_num < arr[idx]:
            max_num = arr[idx]

    return min_num, max_num


def getminmax_tournament(arr, low, high):
    """ Tournament Method
        Divide the array into two parts and compare the maximums and minimums of the two
        parts to get the maximum and the minimum of the whole array.
    """
    if low == high:
        return arr[low], arr[low]

    if abs(low - high) == 1:
        min_num = None
        max_num = None
        if arr[low] > arr[high]:
            max_num = arr[low]
            min_num = arr[high]
        else:
            max_num = arr[high]
            min_num = arr[low]
        return min_num, max_num

    else:
        mid = (low + high) // 2
        min_num_1, max_num_1 = getminmax_tournament(arr, low, mid)
        min_num_2, max_num_2 = getminmax_tournament(arr, mid+1, high)
        return min(min_num_1, min_num_2), max(max_num_1, max_num_2)


def getminmax_pair_compare(arr):
    """ Compare in pairs
    If n is odd then initialize min and max as first element.
    If n is even then initialize min and max as minimum and maximum of the first two elements respectively.
    For rest of the elements, pick them in pairs and compare their maximum and minimum
    with max and min respectively.
    """
    if len(arr) == 0:
        return None, None
    if len(arr) == 1:
        return arr[0], arr[0]

    min_num = None
    max_num = None
    index = 0
    if len(arr) % 2 == 0:
        if arr[0] > arr[1]:
            max_num = arr[0]
            min_num = arr[1]
        else:
            max_num = arr[1]
            min_num = arr[0]
        index = 2
    else:
        max_num = arr[0]
        min_num = arr[0]
        index = 1
    while index < len(arr) - 1:
        if arr[index] > arr[index + 1]:
            max_num = max(arr[index], max_num)
            min_num = min(arr[index + 1], min_num)
        else:
            max_num = max(arr[index + 1], max_num)
            min_num = min(arr[index], min_num)
        index += 2

    return min_num, max_num


def main():
    """ operational function """
    arr = [1000, 11, 445, 100, 3300, 3000]
    print(getminmax_linear_search(arr))
    print(getminmax_tournament(arr, 0, len(arr) - 1))
    print(getminmax_pair_compare(arr))


if __name__ == '__main__':
    main()
