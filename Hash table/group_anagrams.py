# Problem Link :- https://leetcode.com/problems/group-anagrams/solution/

"""Given an array of strings strs, group the anagrams together. You can return the 
answer in any order."""

class Solution(object):
    def groupAnagrams(self, strs):
        from collections import defaultdict
        d = defaultdict(list)
        for s in strs:
            d[tuple(sorted(s))].append(s)
        return d.values()