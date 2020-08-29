"""Given two strings str1 and str2, return the shortest string that 
has both str1 and str2 as subsequences.  If multiple answers exist, 
you may return any of them."""


class Solution(object):
    def shortestCommonSupersequence(self, str1, str2):
        n = len(str1)
        m = len(str2)
        dp = [[0 for i in range(m+1)] for i in range(n+1)]
        for i in range(n+1):
            for j in range(m+1):
                if i == 0 or j == 0:
                    dp[i][j] = 0
                elif str1[i-1] == str2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        i = n
        j = m
        ans = ''
        while i > 0 and j > 0:
            if str1[i-1] == str2[j-1]:
                ans += str1[i-1]
                i -= 1
                j -= 1
            else:
                if dp[i-1][j] > dp[i][j-1]:
                    ans += str1[i-1]
                    i -= 1
                else:
                    ans += str2[j-1]
                    j -= 1
        while i > 0:
            ans += str1[i-1]
            i -= 1
        while j > 0:
            ans += str2[j-1]
            j -= 1
        return ans[::-1]