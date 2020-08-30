"""Write an algorithm to determine if a number n is "happy".
A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the 
sum of the squares of its digits, and repeat the process until 
the number equals 1 (where it will stay), or it loops endlessly 
in a cycle which does not include 1. Those numbers for which this
process ends in 1 are happy numbers.
Return True if n is a happy number, and False if not."""


class Solution(object):
    def isHappy(self, n):
        s = set()
        while (n!=1):
            sm = 0
            curr = n
            while curr > 0:
                sm += (curr % 10) * (curr % 10)
                curr = curr //10
            if sm in s:
                return False
            else:
                s.add(sm)
                n = sm
        return True