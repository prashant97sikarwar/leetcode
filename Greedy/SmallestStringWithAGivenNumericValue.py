#Problem Link:- https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

"""The numeric value of a lowercase character is defined as its position (1-indexed) in the 
alphabet,The numeric value of a string consisting of lowercase characters is defined as the 
sum of its characters' numeric values. You are given two integers n and k. Return the 
lexicographically smallest string with length equal to n and numeric value equal to k."""

class Solution(object):
    def getSmallestString(self, n, k):
        ans = []
        for i in range(n):
            for j in range(26):
                left_pos = 26 * (n-i-1)
                left_val = k-j-1
                if left_pos >= left_val:
                    ans += [chr(97+j)]
                    k = left_val
                    break
        return "".join(ans)