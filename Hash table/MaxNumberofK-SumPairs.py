#Problem Link:- https://leetcode.com/problems/max-number-of-k-sum-pairs/

"""You are given an integer array nums and an integer k. In one operation, you can pick two 
numbers from the array whose sum equals k and remove them from the array.Return the maximum 
number of operations you can perform on the array."""

class Solution(object):
    def maxOperations(self, nums, k):
        d = dict()
        res = 0
        for i in range(len(nums)):
            if k-nums[i] not in d:
                if nums[i] not in d:
                    d[nums[i]] = 1
                else:
                    d[nums[i]] += 1
            else:
                res += 1
                d[k-nums[i]] -= 1
                if d[k-nums[i]] == 0:
                    del d[k-nums[i]]
        return res