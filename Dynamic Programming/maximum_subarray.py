"""Given an integer array nums, find the contiguous subarray 
(containing at least one number) which has the largest sum 
and return its sum."""


class Solution(object):
    def maxSubArray(self, nums):
        curr_sm = nums[0]
        sm_global = nums[0]
        for i in range(1,len(nums)):
            curr_sm = max(curr_sm+nums[i],nums[i])
            sm_global = max(sm_global,curr_sm)
        return sm_global