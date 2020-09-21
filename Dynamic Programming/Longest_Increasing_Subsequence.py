"""Given an unsorted array of integers, find the length of 
longest increasing subsequence."""

class Solution(object):
    def lengthOfLIS(self, nums):
        if len(nums) <= 1:
            return len(nums)
        n = len(nums)
        dp = [1 for i in range(n)]
        for i in range(1,n):
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)