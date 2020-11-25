#Problem link:- https://leetcode.com/problems/sort-integers-by-the-power-value/
"""The power of an integer x is defined as the number of steps needed to transform x into 1 
using the following steps:if x is even then x = x / 2 , if x is odd then x = 3 * x + 1..Given 
three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the
power value in ascending order, if two or more integers have the same power value sort them 
by ascending order.Return the k-th integer in the range [lo, hi] sorted by the power value."""

class Solution(object):
    def getKth(self, lo, hi, k):
        dp = { 1:0 } 
        def power(x):
            if x in dp:
                return dp[x]
            n = dp[x] = 1 + power( (3*x+1) if x&1 else (x >> 1) )
            return n
        
        A = [ (power(x),x) for x in range(lo,hi+1) ]
        return sorted(A)[k-1][1]

