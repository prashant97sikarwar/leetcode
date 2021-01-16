#Problem Link:- https://leetcode.com/problems/degree-of-an-array/

"""Given a non-empty array of non-negative integers nums, the degree of this array is defined as 
the maximum frequency of any one of its elements.Your task is to find the smallest possible 
length of a (contiguous) subarray of nums, that has the same degree as nums."""

class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        from collections import defaultdict
        d = defaultdict(list)
        for i in range(len(nums)):
            d[nums[i]].append(i)
        mx = 0
        for x in d:
            if len(d[x]) > mx:
                mx  = len(d[x])
        ans = 100000
        for x in d:
            if len(d[x]) == mx:
                ans = min(ans,d[x][-1]-d[x][0] + 1)
        return ans