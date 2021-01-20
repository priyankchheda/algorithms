""" check whether two words (or phrases) are anagrams or not

Solution:
    Method 1: Sorting
    Method 2: Counting Characters
"""

def check_anagram(str1, str2):
    if len(str1) != len(str2):
        return False

    count = [0] * 256
    for i in range(len(str1)):
        count[ord(str1[i])] += 1
        count[ord(str2[i])] -= 1

    for i in count:
        if i != 0:
            return False

    return True


print(check_anagram('restful', 'fluster')) # True
print(check_anagram('restful', 'flustez')) # False
