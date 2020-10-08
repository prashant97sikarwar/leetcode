# Problem Link :- https://leetcode.com/problems/complement-of-base-10-integer/

"""For a given number N in base-10, return the complement of it's binary 
representation as a base-10 integer."""

class Solution(object):
    def bitwiseComplement(self, N):
        if N == 0:
            return 1
        import math
        n = int(math.log(N,2)) + 1
        mask = (1 << n) -1 
        return mask ^ N