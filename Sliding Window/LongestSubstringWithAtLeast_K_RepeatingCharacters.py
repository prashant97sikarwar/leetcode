#Problem Link:- https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

"""Given a string s and an integer k, return the length of the longest substring of s such 
that the frequency of each character in this substring is greater than or equal to k."""

class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        n = len(s)

        def helper(s,st,end,k):
            if end < k:
                return 0
            freq = [0 for i in range(26)]
            for i in range(st,end):
                freq[ord(s[i]) - ord("a")] += 1
            for mid in range(st,end):
                if freq[ord(s[mid])-ord("a")] >= k:
                    continue
                midnext = mid+1
                while(midnext < end and freq[ord(s[midnext])-ord("a")] < k):
                    midnext+=1
                return max(helper(s,st,mid,k),helper(s,midnext,end,k))
            return end-st
        return helper(s,0,n,k)