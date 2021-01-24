""" Design an optimal algorithm for checking whether a given string is
    palindrome or not!
"""

def check_palindrome(original):
    for i in range(len(original) // 2):
        if original[i] != original[len(original)-1-i]:
            return False
    return True


def check_palindrome_pythonic(original):
    return original == original[::-1]


print(check_palindrome_pythonic("madam"))
print(check_palindrome("hello"))
