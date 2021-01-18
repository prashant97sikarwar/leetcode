#Problem Link:- https://leetcode.com/problems/first-unique-character-in-a-string/

"""Given a string, find the first non-repeating character in it and return its index. 
If it doesn't exist, return -1."""

class Solution:
    def firstUniqChar(self, s: str) -> int:
        if len(s) == 0:
            return -1
        else:
            d = dict()
            for i in range(len(s)):
                if s[i] not in d:
                    d[s[i]] = 1
                else:
                    d[s[i]] += 1
            for i in range(len(s)):
                if d[s[i]] == 1:
                    return i
            return -1
