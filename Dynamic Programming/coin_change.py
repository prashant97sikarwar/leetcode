"""You are given coins of different denominations and a total amount 
of money amount. Write a function to compute the fewest number of coins 
that you need to make up that amount. If that amount of money cannot 
be made up by any combination of the coins, return -1."""


class Solution(object):
    def coinChange(self, coins, amount):
        dp = [amount + 1 for i in range(amount + 1)]
        dp[0] = 0
        coins.sort()
        for i in range(amount+1):
            for j in range(len(coins)):
                if coins[j] <= i:
                    dp[i] = min(dp[i],1+dp[i-coins[j]])
                else:
                    break
        if dp[amount] > amount:
            return -1
        else:
            return dp[amount]