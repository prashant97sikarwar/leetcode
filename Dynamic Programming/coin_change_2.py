"""You are given coins of different denominations and a total 
amount of money. Write a function to compute the number of 
combinations that make up that amount. You may assume that you 
have infinite number of each kind of coin."""

#solution number 1: space complexity = O(amount*len(coins))

class Solution(object):
    def change(self, amount, coins):
        n = len(coins)
        dp = [[0 for i in range(amount+1)] for j in range(n+1)]
        for i in range(n+1):
            dp[i][0] = 1
        for i in range(1,n+1):
            for j in range(1,amount+1):
                if coins[i-1] <= j:
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[n][amount]
    
        
        
#Solution number 2 : space complexity = O(amount)
class solution(object):
    def change(self, amount, coins):
        n = len(coins)
        dp = [0 for i in range(amount+1)]
        dp[0] = 1
        for i in range(n):
            for j in range(coins[i],amount+1):
                dp[j] += dp[j-coins[i]]
        return dp[amount]

