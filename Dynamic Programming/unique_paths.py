"""A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below).The robot can only move 
either down or right at any point in time. The robot is trying 
to reach the bottom-right corner of the grid (marked 'Finish' 
in the diagram below).How many possible unique paths are there?
"""

class Solution(object):
    def uniquePaths(self, m, n):
        dp = [[0 for i in range(n)] for i in range(m)]
        for i in range(m):
            dp[i][n-1] = 1
        for i in range(n):
            dp[m-1][i] = 1
        for i in range(m-2,-1,-1):
            for j in range(n-2,-1,-1):
                dp[i][j] = dp[i+1][j] + dp[i][j+1]
        return dp[0][0]