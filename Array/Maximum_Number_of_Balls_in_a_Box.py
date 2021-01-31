#Problem Link:- https://leetcode.com/problems/maximum-number-of-balls-in-a-box/

"""You are working in a ball factory where you have n balls numbered from lowLimit up to highLimit 
inclusive (i.e., n == highLimit - lowLimit + 1), and an infinite number of boxes numbered from 1 to 
infinity.Your job at this factory is to put each ball in the box with a number equal to the sum of 
digits of the ball's number. Given two integers lowLimit and highLimit, return the number of balls 
in the box with the most balls."""

class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        d = dict()
        for i in range(lowLimit,highLimit + 1):
            res = self.count(i)
            if res not in d:
                d[res] = 1
            else:
                d[res] += 1
        return max(d.values())
        
    def count(self,num):
        sm = 0
        while num > 0:
            sm += (num) % 10
            num = num // 10
        return sm