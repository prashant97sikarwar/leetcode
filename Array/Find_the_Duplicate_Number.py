# Problem Link :- https://leetcode.com/problems/find-the-duplicate-number/

"""Given an array of integers nums containing n + 1 integers where each integer is in 
the range [1, n] inclusive.There is only one duplicate number in nums, return this duplicate 
number."""

class Solution(object):
    def findDuplicate(self, nums):
        slow = 0
        fast = 0
        check = 0
        
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if fast ==slow :
                break
        while True:
            slow  = nums[slow]
            check = nums[check]
            if slow == check:
                break
        return check