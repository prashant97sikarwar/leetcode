#Problem Link:- https://leetcode.com/problems/sort-characters-by-frequency/

"""Given a string, sort it in decreasing order based on the frequency of characters."""

class Solution:
    def frequencySort(self, s: str) -> str:
        d = dict()
        for i in range(len(s)):
            if s[i] not in d:
                d[s[i]] = 1
            else:
                d[s[i]] += 1
        ans = ""
        for i in sorted(d, key = lambda x: d[x],reverse = True):
            ans += i*d[i]
        return ans