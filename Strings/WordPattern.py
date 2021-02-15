#Problem Link:- https://leetcode.com/problems/word-pattern/

"""Given a pattern and a string s, find if s follows the same pattern.Here follow means a full 
match, such that there is a bijection between a letter in pattern and a non-empty word in s."""

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s = s.split(" ")
        lst = []
        nd = []
        for i in range(len(pattern)):
            for j in range(i+1,len(pattern)):
                if pattern[i] == pattern[j]:
                    lst.append(True)
                else:
                    lst.append(False)
        for i in range(len(s)):
            for j in range(i+1,len(s)):
                if s[i] == s[j]:
                    nd.append(True)
                else:
                    nd.append(False)
        if nd == lst:
            return True
        else:
            return False