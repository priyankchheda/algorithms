""" converting decimal integer to binary using
    stack data structure
"""
from collections import deque


def convert_integer_to_binary(number):
    """ converting decimal integer to binary """
    stack = deque()
    while number:
        stack.append(number % 2)
        number = number // 2

    binary_str = ''
    while stack:
        binary_str += str(stack.pop())

    return binary_str


if __name__ == '__main__':
    print(convert_integer_to_binary(242))
