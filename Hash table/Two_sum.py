#Problem Link :- https://leetcode.com/problems/two-sum/

"""Given an array of integers nums and an integer target, return indices 
of the two numbers such that they add up to target.You may assume that each
input would have exactly one solution, and you may not use the same element 
twice.You can return the answer in any order."""

class Solution(object):
    def twoSum(self, nums, target):
        d = dict()
        n = len(nums)
        for i in range(n):
            if target - nums[i] not in d:
                d[nums[i]] = i
            else:
                return [d[target-nums[i]],i]