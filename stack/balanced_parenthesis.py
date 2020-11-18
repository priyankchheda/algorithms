""" Given a string s containing just the characters
    '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:
    - Open brackets must be closed by the same type of brackets.
    - Open brackets must be closed in the correct order.
"""

from collections import deque

OPEN_PARENTHESES = {'(', '{', '['}
CLOSE_PARENTHESES = {')', '}', ']'}

def is_parentheses_matched(open_paren, close_paren):
    """ checking if open_paren and close_paren are matching """
    if open_paren == '(' and close_paren == ')':
        return True
    if open_paren == '{' and close_paren == '}':
        return True
    if open_paren == '[' and close_paren == ']':
        return True
    return False

def is_valid_parentheses(parentheses_string):
    """ returns true if parentheses string is valid and balanced, else false """
    stack = deque()
    is_valid = True
    index = 0
    while index < len(parentheses_string) and is_valid:
        character = parentheses_string[index]
        if character in OPEN_PARENTHESES:
            stack.append(character)
        elif character in CLOSE_PARENTHESES:
            if not stack:
                is_valid = False
            else:
                top = stack.pop()
                if not is_parentheses_matched(top, character):
                    is_valid = False
        else:
            raise Exception("invalid character")
        index += 1

    if not stack and is_valid:
        return True
    return False


print(is_valid_parentheses("({[]}{}[{({}[])}])")) # True
print(is_valid_parentheses("({[]}{}[{({}])}])")) # False
