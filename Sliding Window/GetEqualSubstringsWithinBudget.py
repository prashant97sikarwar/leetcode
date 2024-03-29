#Problem Link:- https://leetcode.com/problems/get-equal-substrings-within-budget/

"""You are given two strings s and t of the same length. You want to change s to t. Changing the 
i-th character of s to i-th character of t costs |s[i] - t[i]| that is, the absolute difference 
between the ASCII values of the characters.You are also given an integer maxCost.Return the maximum 
length of a substring of s that can be changed to be the same as the corresponding substring of 
twith a cost less than or equal to maxCost.If there is no substring from s that can be changed to 
its corresponding substring from t, return 0."""

class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        left = 0
        res = 0
        cost = 0
        for i in range(len(s)):
            cost += abs(ord(s[i]) - ord(t[i]))
            while left < len(s) and cost > maxCost:
                cost -= abs(ord(s[left]) - ord(t[left]))
                left += 1
            res = max(res,i-left+1)
        return res