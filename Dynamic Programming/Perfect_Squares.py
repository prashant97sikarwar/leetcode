# Problem Link :- https://leetcode.com/problems/perfect-squares/

"""Given a positive integer n, find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n."""

class Solution(object):
    def numSquares(self, n):
        l = []
        x = 1
        while x*x <= n:
            l.append(x*x)
            x += 1
        return self.helper(n,l)
            
    def helper(self,n,l):
        num = len(l)
        dp = [n+1 for i in range(n+1)]
        dp[0] = 0
        for i in range(n+1):
            for j in range(num):
                if i >= l[j]:
                    dp[i] = min(1+dp[i-l[j]],dp[i])
                else:
                    break
        return dp[n]