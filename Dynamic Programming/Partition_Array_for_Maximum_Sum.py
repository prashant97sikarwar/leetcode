"""Given an integer array arr, you should partition the array into (contiguous) 
subarrays of length at most k. After partitioning, each subarray has their values 
changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning."""

class Solution(object):
    def maxSumAfterPartitioning(self, arr, k):
        n = len(arr)
        dp = [0 for i in range(n+1)]
        for i in range(1,n+1):
            for j in range(k):
                if i > j: 
                    dp[i] = max(dp[i],dp[i-j-1] + max(arr[i-j-1:i])*(j+1))
                else:
                    break
        return dp[n]
            
        