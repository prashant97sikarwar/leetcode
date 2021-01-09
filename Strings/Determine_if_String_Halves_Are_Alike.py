#Problem Link:- https://leetcode.com/problems/determine-if-string-halves-are-alike/

"""You are given a string s of even length. Split this string into two halves of equal 
lengths, and let a be the first half and b be the second half.Two strings are alike if 
they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). 
Notice that s contains uppercase and lowercase letters.Return true if a and b are alike. 
Otherwise, return false."""

class Solution(object):
    def halvesAreAlike(self, s):
        vowels = set(['a','e','i','o','u','A','E','I','O','U'])
        cnt1 = 0
        cnt2 = 0
        for i in range(len(s)//2):
            if s[i] in vowels:
                cnt1 += 1
        for i in range(len(s)//2,len(s)):
            if s[i] in vowels:
                cnt2 += 1
        return True if cnt1 == cnt2 else False