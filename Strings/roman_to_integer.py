"""Roman numerals are represented by seven different symbols: I, V, X, L, C, D 
and M.Given a roman numeral, convert it to an integer. Input is guaranteed to 
be within the range from 1 to 3999."""


class Solution(object):
    def romanToInt(self, s):
        ans =   0
        for i in range(len(s)-1):
            if self.fun(s[i]) >= self.fun(s[i+1]):
                ans += self.fun(s[i])
            else:
                ans -= self.fun(s[i])
        ans += self.fun(s[len(s)-1])
        return ans
        
    def fun(self,char):
        dep =  0
        if char == 'I':
            dep = 1
        elif char == 'V':
            dep = 5
        elif char == 'C':
            dep =  100
        elif char == 'M':
            dep = 1000
        elif char == "X":
            dep = 10
        elif char == 'D':
            dep = 500
        elif char == "L":
            dep = 50
        return dep