#Problem Link:- https://leetcode.com/problems/tuple-with-same-product/

"""Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) 
such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d."""

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        d = dict()
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                prod = nums[i] * nums[j]
                if prod not in d:
                    d[prod] = 1
                else:
                    d[prod] += 1
        ans  = 0
        fact = [1 for i in range(10001)]
        for i in range(2,10001):
            fact[i] = i * fact[i-1]
            
        for x in d:
            if d[x] < 2:
                continue
            elif d[x] == 2:
                ans += 8
            else:
                ans += 8 * self.helper(d[x],fact)
        return ans
    
    def helper(self,x,fact):
        return fact[x] // (fact[x-2] * fact[2])