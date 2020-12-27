#Problem Link:- https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

"""Given a string s consisting only of characters a, b and c.Return the number of 
substrings containing at least one occurrence of all these characters a, b and c."""

class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        count = [0 for i in range(3)]
        left = 0
        res = 0
        ans = 0
        for i in range(len(s)):
            count[ord(s[i]) - ord("a")] += 1
            while(left < len(s) and count[0] and count[1] and count[2]):
                res += 1
                count[ord(s[left])-ord("a")] -= 1
                left += 1
            ans += res
        return ans
                