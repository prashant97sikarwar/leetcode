"""You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
Now you have 2 symbols + and -. For each integer, you should choose one from + and - 
as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S."""


class Solution(object):
    def findTargetSumWays(self, nums, S):
        sm = 0
        n = len(nums)
        c = 0
        for i in range(n):
            sm += nums[i]
            if nums[i] == 0:
                c += 1
        dep = (S + sm)//2
        if (S+sm)%2 == 1:
            return 0
        if S > sm:
            return 0
        else:
            return self.power(2,c) * self.CountSubset(nums,n,dep)
    
    def CountSubset(self,arr,n,sm):
        dp = [[0 for i in range(sm+1)] for j in range(n+1)]
        dp[0][0] = 1
        for i in range(1,n+1):
            dp[i][0] = 1
        for i in range(1,n+1):
            for j in range(1,sm+1):
                if arr[i-1] == 0:
                    dp[i][j] = dp[i-1][j]
                elif arr[i-1] <= j:
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[n][sm]
    def power(self,m,n):
        if n == 0:
            return 1
        res = 1
        while n > 0:
            if n&1:
                res *= m
                n -= 1
            else:
                m *= m
                n = n//2
        return res