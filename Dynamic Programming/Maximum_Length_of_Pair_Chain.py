""" You are given n pairs of numbers. In every pair, the first number is 
always smaller than the second number.Now, we define a pair (c, d) can 
follow another pair (a, b) if and only if b < c. Chain of pairs can be 
formed in this fashion.Given a set of pairs, find the length longest chain 
which can be formed. You needn't use up all the given pairs. You can select 
pairs in any order. """


class Solution(object):
    def findLongestChain(self, pairs):
        pairs.sort()
        n = len(pairs)
        dp = [1 for i in range(n)]
        for i in range(1,n):
            for j in range(i):
                if pairs[i][0] > pairs[j][1]:
                    dp[i] = max(dp[i],1 + dp[j])
        mx = -1000
        for i in range(n):
            mx = max(mx,dp[i])
        return mx
        