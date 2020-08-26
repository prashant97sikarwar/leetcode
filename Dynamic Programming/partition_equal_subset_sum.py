"""Given a non-empty array containing only positive integers, find if 
the array can be partitioned into two subsets such that the sum of 
elements in both subsets is equal."""


class Solution(object):
    def canPartition(self, nums):
        n = len(nums)
        sm = 0
        for i in range(n):
            sm += nums[i]
        if sm % 2 == 1:
            return False
        return self.subset(nums,sm//2,n)
    
    def subset(self,nums,sm,n):
        dp = [[False for i in range(sm+1)] for j in range(n+1)]
        dp[0][0] = True
        for i in range(1,sm+1):
            dp[0][i] = False
        for i in range(1,n+1):
            dp[i][0] = True
        for i in range(1,n+1):
            for j in range(1,sm+1):
                if nums[i-1] <= j:
                    dp[i][j] = dp[i-1][j-nums[i-1]] or dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[n][sm]