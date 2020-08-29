"""Given two words word1 and word2, find the minimum number of steps 
required to make word1 and word2 the same, where in each step you can 
delete one character in either string."""


class Solution(object):
    def minDistance(self, word1, word2):
        n = len(word1)
        m = len(word2)
        dp = [[0 for i in range(m+1)] for i in range(n+1)]
        for i in range(n+1):
            for j in range(m+1):
                if i == 0 or j == 0:
                    dp[i][j] = 0
                elif word1[i-1] == word2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return n + m - 2*dp[n][m]