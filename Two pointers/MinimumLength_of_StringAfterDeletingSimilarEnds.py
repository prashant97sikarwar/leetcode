#Problem Link:- https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

"""Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply 
the following algorithm on the string any number of times:
1.Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
2.Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
3.The prefix and the suffix should not intersect at any index.
4.The characters from the prefix and suffix must be the same.
5.Delete both the prefix and the suffix.
Return the minimum length of s after performing the above operation any number of times (
possibly zero times)."""

class Solution:
    def minimumLength(self, s: str) -> int:
        n = len(s)
        l = 0
        r = n-1
        while r > l and s[l] == s[r]:
            char = s[l]
            while l < n and s[l] == char:
                l += 1
            while r > -1 and s[r] == char:
                r -= 1
        return max(0,r-l+1)