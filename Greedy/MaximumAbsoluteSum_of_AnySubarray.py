#Problem Link:- https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

"""You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., 
numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).Return the maximum absolute 
sum of any (possibly empty) subarray of nums."""

class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        n = len(nums)
        cur_sum = nums[0]
        global_sum = nums[0]
        for i in range(1,n):
            cur_sum = max(nums[i],cur_sum + nums[i])
            global_sum = max(global_sum,cur_sum)
            
        mnsm = nums[0]
        glmn = nums[0]
        for i in range(1,n):
            mnsm = min(nums[i],nums[i] + mnsm)
            glmn = min(glmn,mnsm)
        return max(global_sum, abs(glmn))