"""Given an integer, write a function to determine if it is a power of three."""


class Solution(object):
    def isPowerOfThree(self, n):
        if n <= 0:
            return False
        while n > 0:
            if n % 3 == 0:
                while n % 3 == 0:
                    n = n//3
            else:
                break
        if n > 1:
            return False
        else:
            return True