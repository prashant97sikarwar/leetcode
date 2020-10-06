# Problem Link :- https://leetcode.com/problems/minimum-path-sum/

"""Given a m x n grid filled with non-negative numbers, find a path from 
top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time."""


class Solution(object):
    def minPathSum(self, grid):
        n = len(grid)
        m = len(grid[0])
        dp = [[0 for i in range(m)] for i in range(n)]
        dp[0][0] = grid[0][0]
        for i in range(1,n):
            dp[i][0] = grid[i][0] + dp[i-1][0]
        for i in range(1,m):
            dp[0][i] = grid[0][i] + dp[0][i-1]
        for i in range(1,n):
            for j in range(1,m):
                dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + grid[i][j]
        return dp[n-1][m-1]
            