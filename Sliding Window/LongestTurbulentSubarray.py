#Problem Link:- https://leetcode.com/problems/longest-turbulent-subarray/

"""Given an integer array arr, return the length of a maximum size turbulent subarray of 
arr.A subarray is turbulent if the comparison sign flips between each adjacent pair of 
elements in the subarray."""

class Solution:
    def maxTurbulenceSize(self, arr):
        n = len(arr)
        res = 1
        left = 0
        for i in range(1,n):
            c = cmp(arr[i-1],arr[i])
            if c == 0:
                left = i
            elif i == n-1 or c * cmp(arr[i],arr[i+1]) != -1:
                res = max(res,i-left+1)
                left = i
        return res