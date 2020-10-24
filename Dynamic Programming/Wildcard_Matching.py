#Problem Link :- https://leetcode.com/problems/wildcard-matching/

"""Given an input string (s) and a pattern (p), implement wildcard pattern matching with 
support for '?' and '*' where:'?' Matches any single character.'*' Matches any sequence of 
characters (including the empty sequence).The matching should cover the entire input string 
(not partial)."""

class Solution(object):
    def isMatch(self, s, p):
        n = len(s)
        m = len(p)
        dp = [[0 for i in range(m+1)] for i in range(n+1)]
        dp[0][0] = True
        for i in range(1,n+1):
            dp[i][0] = False
        for i in range(1,m+1):
            if p[i-1] == '*':
                dp[0][i] = dp[0][i-1]
            elif p[i-1] == '?':
                dp[0][i] = False
            else:
                dp[0][i] = False
        for i in range(1,n+1):
            for j in range(1,m+1):
                if s[i-1] == p[j-1]: 
                    dp[i][j] = dp[i-1][j-1]
                elif p[j-1] == '*':
                    dp[i][j] = dp[i][j-1] or dp[i-1][j]
                elif p[j-1] == '?':
                    dp[i][j] = dp[i-1][j-1]
                elif s[i-1] != p[j-1]:
                    dp[i][j] = False
        return dp[n][m]
