""" algorithm to find the sum of contiguous subarray within a one-dimensional
    array of numbers which has the largest sum!

Solution:
    - If the array contains all negative numbers: the solution is the number
      in the array with the smallest magnitude
    - If the array contains all positive numbers: solution is the sum of all
      the items
    - If it contains negative and positive numbers as well thats when the
      problem gets a bit more complex
      solution: Kadane's Algorithm
"""

def kadane_algorithm(nums):
    max_global = nums[0]
    max_current = nums[0]

    for i in range(1, len(nums)):
        max_current = max(nums[i], max_current + nums[i])
        if max_current > max_global:
            max_global = max_current

    return max_global

print(kadane_algorithm([1, -2, 3, 4, -5, 8]))
