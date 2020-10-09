# Problem Link :- https://leetcode.com/problems/sqrtx/

"""Compute and return the square root of x, where x is guaranteed to be a 
non-negative integer.Since the return type is an integer, the decimal digits 
are truncated and only the integer part of the result is returned."""

class Solution(object):
    def mySqrt(self, x):
        import math
        return int(math.sqrt(x))