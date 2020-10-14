# Problem Link :- https://leetcode.com/problems/sum-of-two-integers/
"""Calculate the sum of two integers a and b, but you are not allowed 
to use the operator + and -."""

class Solution(object):
    def getSum(self, a, b):
        if a == 0:
            return b
        elif b == 0:
            return a
        elif a > 0 and b > 0:
            return self.add(a,b)
        elif a < 0 and b < 0:
            return -self.add(abs(a),abs(b))
        elif a < 0 and b > 0:
            if abs(a) < abs(b):
                return self.minus(b,abs(a))
            else:
                return -self.minus(abs(a),b)
        elif a > 0 and b < 0:
            if abs(b) > abs(a):
                return -self.minus(abs(b),a)
            else:
                return self.minus(a,abs(b))
            
        
    def add(self,x,y):
        while y != 0:
            carry = x & y
            x = x^y
            y = carry << 1
        return x
    
    def minus(self,x,y):
        while y != 0:
            borrow = ~x&y
            x  = x^y
            y = borrow << 1
        return x
    
    