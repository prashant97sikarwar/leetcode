#Problem Link:- https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

"""Given a string s and an integer k.Return the maximum number of vowel letters in any 
substring of s with length k."""

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        lst = ['a','e','i','o','u']
        lst = set(lst)
        left,res = 0,0
        ans = 0
        n = len(s)
        for i in range(n):
            if s[i] in lst:
                ans += 1
            while (left < n and (i-left+1) > k):
                if s[left] in lst:
                    ans -= 1
                left+=1
            res = max(res,ans)
        return res