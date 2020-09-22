"""Given two words word1 and word2, find the minimum number of operations 
required to convert word1 to word2.You have the following 3 operations 
permitted on a word:
    Insert a character
    Delete a character
    Replace a character"""


class Solution(object):
    def minDistance(self, word1, word2):
        n = len(word1)
        m = len(word2)
        dp = [[0 for i in range(m+1)] for i in range(n+1)]
        for i  in range(n+1):
            for j in range(m+1):
                if i == 0:
                    dp[i][j] = j
                elif j == 0:
                    dp[i][j] = i
                elif word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
        return dp[n][m]