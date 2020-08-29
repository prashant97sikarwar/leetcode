"""Say you have an array for which the ith element is the price 
of a given stock on day i. If you were only permitted to complete 
at most one transaction (i.e., buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one."""


class Solution(object):
    def maxProfit(self, prices):
        import math
        mx = 0
        mn = float('inf')
        for i in range(len(prices)):
            if prices[i] < mn:
                mn = prices[i]
            else:
                mx = max(mx,prices[i] - mn)
        return mx