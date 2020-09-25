"""A robot is located at the top-left corner of a m x n grid (marked 'Start' 
in the diagram below).The robot can only move either down or right at any 
point in time. The robot is trying to reach the bottom-right corner of the 
grid (marked 'Finish' in the diagram below).Now consider if some obstacles 
are added to the grids. How many unique paths would there be?
"""

class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        n = len(obstacleGrid)
        m = len(obstacleGrid[0])
        if obstacleGrid[n-1][m-1] == 1:
            return 0
        dp = [[0 for i in range(m)] for j in range(n)]
        dp[n-1][m-1] = 1
        for i in range(n-2,-1,-1):
            if obstacleGrid[i][m-1] == 0:
                dp[i][m-1] += dp[i+1][m-1]
            else:
                dp[i][m-1] = 0
        for i in range(m-2,-1,-1):
            if obstacleGrid[n-1][i] == 0:
                dp[n-1][i] += dp[n-1][i+1]
            else:
                dp[n-1][i] = 0
        for i in range(n-2,-1,-1):
            for j in range(m-2,-1,-1):
                if obstacleGrid[i][j] == 0:
                    dp[i][j] = dp[i+1][j] + dp[i][j+1]
                else:
                    dp[i][j] = 0
        return dp[0][0]