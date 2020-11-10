# Problem Link :- https://leetcode.com/problems/ones-and-zeroes/

"""You are given an array of binary strings strs and two integers m and n.Return the size 
of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y."""

class Solution:
    def findMaxForm(self, strs,m,n):
        if len(strs) == 0:
            return 
        dp = [[0 for i in range(n+1)] for i in range(m+1)]
        l = len(strs)
        for i in range(1,l+1):
            freq0 = strs[i-1].count("0")
            freq1 = strs[i-1].count("1")
            for j in range(m,freq0-1,-1):
                for k in range(n,freq1-1,-1):
                    dp[j][k] = max(dp[j][k],dp[j-freq0][k-freq1] + 1)
        return dp[m][n]