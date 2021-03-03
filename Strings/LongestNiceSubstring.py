#Problem Link:- https://leetcode.com/problems/longest-nice-substring/

"""A string s is nice if, for every letter of the alphabet that s contains, it appears both in 
uppercase and lowercase. Given a string s, return the longest substring of s that is nice. If there
are multiple, return the substring of the earliest occurrence. If there are none, return an empty 
string."""

class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        ans = ""
        for i in range(len(s)):
            for j in range(i+1,len(s)):
                if self.helper(s[i:j+1]):
                    if len(ans) < j-i+1:
                        ans = s[i:j+1]
        return ans
    
    def helper(self,s):
        d = set()
        for i in range(len(s)):
            if s[i] not in d:
                d.add(s[i])
        for i in range(len(s)):
            if s[i].islower():
                if chr(ord(s[i])-32) not in d:
                    return False
            else:
                if chr(ord(s[i])+32) not in d:
                    return False
        return True