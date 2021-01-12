#Problem Link:- https://leetcode.com/problems/calculate-money-in-leetcode-bank/

"""Hercy wants to save money for his first car. He puts money in the Leetcode bank every 
day.He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, 
he will put in $1 more than the day before. On every subsequent Monday, he will put in $1
more than the previous Monday.Given n, return the total amount of money he will have in the
Leetcode bank at the end of the nth day."""

class Solution(object):
    def totalMoney(self, n):
        if n <= 7:
            return n*(n+1)/2
        lap = n // 7
        res = 0
        res += lap*(2*28 + (lap-1)*7) // 2
        left = n - (lap * 7)
        for i in range(left):
            res += (lap+1+i)
        return res
        