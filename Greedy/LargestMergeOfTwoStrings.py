#Problem Link:- https://leetcode.com/problems/largest-merge-of-two-strings/

"""You are given two strings word1 and word2. You want to construct a string merge in the 
following way: while either word1 or word2 are non-empty, choose one of the following options:
1.If word1 is non-empty, append the first character in word1 to merge and delete it from word1.
2.If word2 is non-empty, append the first character in word2 to merge and delete it from word2.
Return the lexicographically largest merge you can construct."""

class Solution:
    def largestMerge(self, word1: str, word2: str) -> str:
        merge = ""
        n,m = len(word1),len(word2)
        first,sec = 0,0
        while first < n and sec < m:
            if word1[first] == word2[sec]:
                if word1[first:] > word2[sec:]:
                    merge += word1[first]
                    first += 1
                else:
                    merge += word2[sec]
                    sec += 1
            else:
                if word1[first] > word2[sec]:
                    merge += word1[first]
                    first += 1
                else:
                    merge += word2[sec]
                    sec += 1
        while first < n:
            merge += word1[first]
            first += 1
        while sec < m:
            merge += word2[sec]
            sec += 1
        return merge