#Problem Link:- https://leetcode.com/problems/count-good-meals/

"""A good meal is a meal that contains exactly two different food items with a sum of 
deliciousness equal to a power of two.Given an array of integers deliciousness where 
deliciousness[i] is the deliciousness of the i​​​​​​th​​​​​​​​ item of food, return the number of 
different good meals you can make from this list modulo 109 + 7."""

class Solution(object):
    def countPairs(self, deliciousness):
        from collections import defaultdict
        d = defaultdict(int)
        n = len(deliciousness)
        l = []
        for i in range(22):
            l.append(pow(2,i))
        cnt = 0
        for i in range(n):
            for j in range(len(l)):
                cnt += d[l[j] - deliciousness[i]]
            d[deliciousness[i]] += 1
        return (cnt % 1000000007)