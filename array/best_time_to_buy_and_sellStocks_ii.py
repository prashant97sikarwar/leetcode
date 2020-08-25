"""Say you have an array prices for which the ith element is 
the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete 
as many transactions as you like (i.e., buy one and sell one share 
of the stock multiple times)."""


class Solution(object):
    def maxProfit(self, prices):
        ans = 0
        for i in range(len(prices)-1):
            if prices[i] < prices[i+1]:
                ans += prices[i+1] - prices[i]
        return ans