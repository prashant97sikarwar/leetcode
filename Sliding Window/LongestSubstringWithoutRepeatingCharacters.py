#Problem Link:- https://leetcode.com/problems/longest-substring-without-repeating-characters/

"""Given a string s, find the length of the longest substring without repeating 
characters."""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        freq = [0 for i in range(200)]
        res,left = 0,0
        n = len(s)
        for i in range(n):
            freq[ord(s[i])-ord(" ")] += 1
            while (left < n and freq[ord(s[i])-ord(" ")] > 1):
                freq[ord(s[left])-ord(" ")] -= 1
                left += 1
            res = max(res,i-left+1)
        return res