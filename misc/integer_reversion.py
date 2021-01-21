""" Design an efficient algorithm to reverse a given integer. For example if
    the input of the algorithm is 1234 then the output should be 4321.
"""

def integer_reverse(number):
    result = 0

    while number:
        remainder = number % 10
        result = result * 10 + remainder
        number = number // 10

    return result

print(integer_reverse(1234))
