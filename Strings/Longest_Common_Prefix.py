# Problem Link :- https://leetcode.com/problems/longest-common-prefix/

"""Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string ""."""

class Solution(object):
    def longestCommonPrefix(self, strs):
        if len(strs) == 0:
            return ""
        if len(strs) == 1:
            return strs[0]
        length = 1000
        for i in range(len(strs)):
            length = min(length,len(strs[i]))
        res = ""
        for i in range(length):
            temp = strs[0][i]
            for j in range(1,len(strs)):
                if temp != strs[j][i]:
                    return res
            res += strs[j][i]
        return res
        