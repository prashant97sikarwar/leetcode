"""Given an integer array arr and an integer difference, return the length of 
the longest subsequence in arr which is an arithmetic sequence such that the 
difference between adjacent elements in the subsequence equals difference."""


class Solution(object):
    def longestSubsequence(self, arr, difference):
        dp = dict()
        mx = 0
        for num in arr:
            if num - difference in dp:
                dp[num] = 1 + dp[num-difference]
            else:
                dp[num] = 1
            mx = max(dp[num],mx)
        return mx
            