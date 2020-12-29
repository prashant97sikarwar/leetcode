#Problem Link:- https://leetcode.com/problems/permutation-in-string/

"""Given two strings s1 and s2, write a function to return true if s2 contains the 
permutation of s1. In other words, one of the first string's permutations is the substring 
of the second string."""

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        freq = [0 for i in range(26)]
        freq2 = [0 for i in range(26)]
        n = len(s1)
        m = len(s2)
        left = 0
        if n > m:
            return False
        for i in range(n):
            freq[ord(s1[i])-ord("a")] += 1
        for i in range(m):
            freq2[ord(s2[i])-ord("a")] += 1
            while (left < m and i-left+1>n):
                freq2[ord(s2[left])-ord("a")] -= 1
                left+=1
            if i-left+1 == n:
                if freq == freq2:
                    return True
        return False