#Problem Link:- https://leetcode.com/problems/longest-repeating-character-replacement/

"""iven a string s that consists of only uppercase English letters, you can perform at 
most k operations on that string.In one operation, you can choose any character of the 
string and change it to any other uppercase English character.Find the length of the 
longest sub-string containing all repeating letters you can get after performing the 
above operations."""

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = [0 for i in range(26)]
        left = 0
        res = 0
        max_count = 0
        for i in range(len(s)):
            freq[ord(s[i]) - ord('A')] += 1
            curr_count = freq[ord(s[i]) - ord('A')]
            max_count = max(max_count,curr_count)
            while(left < len(s) and i-left - max_count + 1 > k):
                freq[ord(s[left]) - ord('A')] -= 1
                left += 1
            res = max(res,i-left+1)
        return res