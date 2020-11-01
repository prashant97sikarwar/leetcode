# Problem Link :- https://leetcode.com/problems/unique-binary-search-trees/
"""Given n, how many structurally unique BST's (binary search trees) 
that store values 1 ... n?"""

class Solution:
    def numTrees(self, n: int) -> int:
        num = 39
        dp = [0 for i in range(num+1)]
        dp[0] = 1
        for i in range(1,num+1):
            dp[i] = i*dp[i-1]
        ans = dp[2*n]/(dp[n]*dp[n]*(n+1))
        return int(ans)
        