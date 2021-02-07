#Problem Link:- https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

"""Given an array nums, return true if the array was originally sorted in non-decreasing 
order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array."""

class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        for idx in range(n):
            if nums[idx:] + nums[:idx] == sorted(nums):
                return True
        return False