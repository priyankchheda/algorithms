""" Largest Rectangle in Histogram
    leetcode: https://leetcode.com/problems/largest-rectangle-in-histogram/

    Given n non-negative integers representing the histogram's bar height
    where the width of each bar is 1, find the area of largest rectangle in
    the histogram.

    Sample:
        Input: [2,1,5,6,2,3]
        Output: 10
"""

from collections import deque


def largest_rectangle_area(heights):
    """ return largest rectangle in histogram """
    stack = [-1]
    max_area = 0

    for i in range(len(heights)):
        # we are saving indexes in stack that is why we comparing last element in stack
        # with current height to check if last element in stack not bigger then
        # current element
        while stack[-1] != -1 and heights[stack[-1]] >= heights[i]:
            lastElementIndex = stack.pop()
            max_area = max(max_area, heights[lastElementIndex] * (i - stack[-1] - 1))
        stack.append(i)

    # we went through all elements of heights array
    # let's check if we have something left in stack
    while stack[-1] != -1:
        lastElementIndex = stack.pop()
        max_area = max(max_area, heights[lastElementIndex] * (len(heights) - stack[-1] - 1))

    return max_area


def main():
    """ operational function """
    print(largest_rectangle_area([2, 1, 5, 6, 2, 3]))


if __name__ == "__main__":
    main()
