#Problem Link: https://leetcode.com/problems/reorganize-string/

"""Given a string S, check if the letters can be rearranged so that two characters that 
are adjacent to each other are not the same.If possible, output any possible result.  
If not possible, return the empty string."""

class Solution:
    def reorganizeString(self, s: str) -> str:
        n = len(s)
        d = {}
        for i in range(n):
            if s[i] not in d:
                d[s[i]] = 1
            else:
                d[s[i]] += 1
                if d[s[i]] > (n+1)//2:
                    return ""
        s = sorted(s)
        s = sorted(s,key = lambda x:s.count(x))
        ans = [None]*n
        ans[::2],ans[1::2] = s[n//2:],s[:n//2]
        return "".join(ans)