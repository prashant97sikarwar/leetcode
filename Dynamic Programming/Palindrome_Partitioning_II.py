"""Given a string s, partition s such that every substring of the 
partition is a palindrome.Return the minimum cuts needed for a 
palindrome partitioning of s."""


class Solution(object):
    def minCut(self, s):
        n = len(s)
        dp = [0]*(n+1)
        isPal = [[False for i in range(n+1)] for i in range(n+1)]
        for i in range(n):
            isPal[i][i] = True
        for l in range(2,n+1):
            for i in range(n-l+1):
                j = i + l -1
                if l== 2:
                    isPal[i][j] = (s[i] == s[j])
                else:
                    isPal[i][j] = ((s[i] == s[j]) and isPal[i+1][j-1])
        for i in range(n):
            if isPal[0][i] == True:
                dp[i] = 0
            else:
                dp[i] = float('inf')
                for j in range(i):
                    if isPal[j+1][i] == True:
                        dp[i] = min(dp[i],1+dp[j])
        return dp[n-1]
                    