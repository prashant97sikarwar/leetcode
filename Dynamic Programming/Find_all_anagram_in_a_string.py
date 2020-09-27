"""Given a string s and a non-empty string p, find all the start indices 
of p's anagrams in s.Strings consists of lowercase English letters only 
and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter."""

class Solution(object):
    def findAnagrams(self, s, p):
        if len(p) > len(s):
            return 
        first = dict()
        second = dict()
        for i in range(len(p)):
            if p[i] not in first:
                first[p[i]] = 1
            else:
                first[p[i]] += 1
        for i in range(len(p)):
            if s[i] not in second:
                second[s[i]] = 1
            else:
                second[s[i]] += 1
        l = []
        if first == second:
            l.append(0)
        for i in range(len(p),len(s)):
            j = i - len(p) 
            second[s[j]] -= 1
            if second[s[j]] == 0:
                del second[s[j]]
            if s[i] not in second:
                second[s[i]] = 1
            elif s[i] in second:
                second[s[i]] += 1
            if first == second:
                l.append(j + 1)
        return l
            
            