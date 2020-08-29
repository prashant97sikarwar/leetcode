"""Given a string s, find the longest palindromic subsequence's length 
in s. You may assume that the maximum length of s is 1000."""


class Solution(object):
    def longestPalindromeSubseq(self, s):
        str2 = s[::-1]
        return self.answer(s,str2)
        
    def answer(self,s,str2):
        n = len(s)
        m = len(str2)
        dp = [[0 for i in range(m+1)] for j in range(n+1)]
        for i in range(n+1):
            for j in range(m+1):
                if i == 0 or j == 0:
                    dp[i][j] = 0
                elif s[i-1] == str2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[n][m]