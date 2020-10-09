# Problem Link :- https://leetcode.com/problems/reverse-integer/
"""Given a 32-bit signed integer, reverse digits of an integer.Note:Assume we are dealing 
with an environment that could only store integers within the 32-bit signed integer range: 
[−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when
the reversed integer overflows."""

class Solution(object):
    def reverse(self, x):
        if x == 0:
	        return 0
        if x > 0:
            rev = str(x)
            rev = rev[::-1]
            if int(rev) > 2 ** 31:
                return 0
            return (int(rev))
        if x < 0:
            x = x * -1
            rev = str(x)
            rev = rev[::-1]
            if int(rev) > 2 ** 31:
                return 0
            return (int(rev) * -1)