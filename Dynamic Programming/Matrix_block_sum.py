"""Given a m * n matrix mat and an integer K, return a matrix answer where 
each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, 
j - K <= c <= j + K, and (r, c) is a valid position in the matrix."""


class Solution(object):
    def matrixBlockSum(self, mat, K):
        n = len(mat)
        m = len(mat[0])
        dp = [[0 for i in range(m+1)] for i in range(n+1)]
        for i in range(1,n+1):
            for j in range(1,m+1):
                dp[i][j] = mat[i-1][j-1] + dp[i-1][j]  + dp[i][j-1] - dp[i-1][j-1] 
        for i in range(1,n+1):
            for j in range(1,m+1):
                r1 = max(i-K-1,0)
                c1 = max(j-K-1,0)
                r2 = min(i+K,n)
                c2 = min(j+K,m)
                mat[i-1][j-1] = dp[r2][c2] - dp[r1][c2] - dp[r2][c1] + dp[r1][c1]
        return mat