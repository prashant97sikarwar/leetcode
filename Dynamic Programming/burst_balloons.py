"""Given n balloons, indexed from 0 to n-1. Each balloon is painted with a 
number on it represented by array nums. You are asked to burst all the 
balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] 
coins. Here left and right are adjacent indices of i. After the burst, the 
left and right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely."""

class Solution(object):
    def maxCoins(self, nums):
        dep = [1]
        nums = dep + nums + dep
        dp = [[-1 for i in range(len(nums))] for i in range(len(nums))]
        return self.solve(nums,1,len(nums)-1,dp)
    
    def solve(self,arr,i,j,dp):
        mn = -8
        if i >= j:
            return 0
        elif dp[i][j] != -1:
            return dp[i][j]
        else:
            for k in range(i,j):
                ans = self.solve(arr,i,k,dp) + self.solve(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j]
                if ans > mn:
                    mn = ans
            dp[i][j] = mn
            return dp[i][j]