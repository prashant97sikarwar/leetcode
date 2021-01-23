#Problem Link:- https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

"""A decimal number is called deci-binary if each of its digits is either 0 or 1 without any 
leading zeros. Given a string n that represents a positive decimal integer, return the minimum 
number of positive deci-binary numbers needed so that they sum up to n."""

class Solution(object):
    def minPartitions(self, n):
        mx = 0
        for i in range(len(n)):
            if int(n[i]) > mx:
                mx = int(n[i])
        return mx
    

