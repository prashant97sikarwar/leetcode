# Problem Link :- https://leetcode.com/problems/number-complement/

"""Given a positive integer num, output its complement number. The complement 
strategy is to flip the bits of its binary representation."""

class Solution(object):
    def findComplement(self, num):
        mult = 1
        ans = 0
        while num:
            if num&1 == 0:
                ans += (mult*1)
            mult <<= 1
            num >>= 1
        return ans
