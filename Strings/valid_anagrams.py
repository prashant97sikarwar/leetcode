"""Given two strings s and t , write a function to determine if t is an anagram of s."""


class Solution(object):
    def isAnagram(self, s, t):
        n = len(s)
        if len(s) != len(t):
            return False
        arr = [0 for i in range(26)]
        for i in range(n):
            arr[ord(s[i])-ord('a')] += 1
        for i in range(n):
            arr[ord(t[i]) - ord('a')] -= 1
        for i in range(26):
            if arr[i] != 0:
                return False
        return True
        