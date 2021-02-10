#Problem Link:- https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

"""Given an integer n, return the decimal value of the binary string formed by concatenating 
the binary representations of 1 to n in order, modulo 109 + 7."""

class Solution(object):
    def concatenatedBinary(self, n):
        res = 0
        cur_len = 0
        MOD = 1000000007
        for i in range(1,n+1):
            if (i & (i-1)) == 0:
                cur_len += 1
            res = (res << cur_len) % MOD
            res += i % MOD
        return res % MOD

