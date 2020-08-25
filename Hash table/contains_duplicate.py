"""Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in 
the array, and it should return false if every element is distinct."""


class Solution(object):
    def containsDuplicate(self, nums):
        s = set()
        for i in range(len(nums)):
            if nums[i] not in s:
                s.add(nums[i])
            else:
                return True
        return False
        