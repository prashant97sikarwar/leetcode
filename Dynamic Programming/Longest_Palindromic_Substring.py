"""Given a string s, find the longest palindromic substring in s. You may 
assume that the maximum length of s is 1000."""

class Solution(object):
    def longestPalindrome(self, s):
        if len(s) <= 1:
            return s
        res = 0
        for i in range(len(s)):
            l1 = self.helper(s,i,i)
            l2 = self.helper(s,i,i+1)
            l = max(l1,l2)
            if l > res:
                res = l
                start = i - (l-1)//2
                end = i + l//2
        return s[start:end+1]
            
            
    def helper(self,s,i,j):
        while i >= 0 and j < len(s) and s[i] == s[j]:
            i -= 1
            j += 1
        return j - i - 1
            
        
        