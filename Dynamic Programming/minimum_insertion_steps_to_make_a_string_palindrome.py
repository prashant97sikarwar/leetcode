"""Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.
A Palindrome String is one that reads the same backward as well as forward."""


class Solution(object):
    def minInsertions(self, s):
        n = len(s)
        l = s[::-1]
        return n - self.helper(s,l,n)
        
        
    def helper(self,str1,str2,n):
        dp = [[0 for i in range(n+1)] for i in range(n+1)]
        for i in range(n+1):
            for j in range(n+1):
                if i == 0 or j == 0:
                    dp[i][j] = 0
                elif str1[i-1] == str2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[n][n]
        
        