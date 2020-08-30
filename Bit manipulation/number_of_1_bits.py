"""Write a function that takes an unsigned integer and 
return the number of '1' bits it has"""


class Solution(object):
    def hammingWeight(self, n):
        n = bin(n)[2:]
        res = 0
        for i in range(len(n)):
            if n[i] == '1':
                res += 1
        return res
                