#Problem Link :- https://leetcode.com/problems/triangle/

"""Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below."""

class Solution:
    def minimumTotal(self, triangle):
        n = len(triangle)
        dp = [[0 for x in range(n)] for y in range(n)] 
        
        dp[0][0] = triangle[0][0]
        for i in range(1,n):
            m = len(triangle[i])
            for j in range(m):
                if j == 0:
                    dp[i][j] = dp[i-1][j] + triangle[i][j]
                elif j == m-1:
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j]
                else:
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]
        return min(dp[-1])
                
