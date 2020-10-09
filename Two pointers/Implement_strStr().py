# Problem Link :- https://leetcode.com/problems/implement-strstr/
"""Implement strStr().Return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack."""

class Solution(object):
    def strStr(self, haystack, needle):
        if len(needle) == 0:
            return 0
        l = 0
        i = 0
        n = len(haystack)
        m = len(needle)
        if m > n:
            return -1
        ind = -1
        while i < n:
            if l >= m:
                return ind
            elif haystack[i] == needle[l]:
                if ind == -1:
                    ind = i
                    l += 1
                    i += 1
                else:
                    l += 1
                    i += 1
            else:
                i = i+1 if ind == -1 else ind + 1
                l = 0 
                ind = -1
        return ind if l >= m else -1
                