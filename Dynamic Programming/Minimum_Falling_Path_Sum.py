"""Given a square array of integers A, we want the minimum sum of 
a falling path through A.A falling path starts at any element in 
the first row, and chooses one element from each row.  The next 
row's choice must be in a column that is different from the previous 
row's column by at most one."""


class Solution(object):
    def minFallingPathSum(self, A):
        n = len(A)
        dp = [[0 for i in range(n)] for i in range(n)]
        for i in range(n):
            dp[n-1][i] = A[n-1][i]
        for i in range(n-2,-1,-1):
            for j in range(n):
                dp[i][j] = A[i][j]
                mn = dp[i+1][j]
                if j-1 >= 0:
                    mn = min(mn,dp[i+1][j-1])
                if j + 1 <= n-1:
                    mn = min(mn,dp[i+1][j+1])
                dp[i][j] += mn
        return min(dp[0])
            
        