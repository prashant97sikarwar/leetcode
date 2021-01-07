#Problem Link:- https://leetcode.com/problems/maximum-product-subarray/

"""Given an integer array nums, find the contiguous subarray within an array (containing 
at least one number) which has the largest product."""

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return -1
        res = nums[0]
        curr_max = nums[0]
        curr_min = nums[0]
        for i in range(1,n):
            temp = curr_max
            curr_max = max(max(curr_max*nums[i],curr_min*nums[i]),nums[i])
            curr_min = min(min(temp*nums[i],curr_min*nums[i]),nums[i])
            
            if (curr_max > res):
                res = curr_max
        return res