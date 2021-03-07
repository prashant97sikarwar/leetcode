# Problem Link:- https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

"""Given an integer n, return true if it is possible to represent n as the sum of distinct powers 
of three. Otherwise, return false."""

class Solution(object):
    def checkPowersOfThree(self, n):
        l = [1]
        num = 3
        s = set()
        s.add(1)
        while num <= n:
            for i in range(len(l)):
                df = l[i] + num
                if df == n:
                    return True
                l.append(df)
                s.add(df)
            l.append(num)
            s.add(num)
            num *= 3
        return True if n in s else False