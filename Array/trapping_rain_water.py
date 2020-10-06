# Problem Link :- https://leetcode.com/problems/trapping-rain-water/

"""Given n non-negative integers representing an elevation map where the width of each 
bar is 1, compute how much water it is able to trap after raining."""

class Solution(object):
    def trap(self, height):
        n = len(height)
        if n <= 1:
            return 0
        left = [0 for i in range(n)]
        right = [0 for i in range(n)]
        left[0] = max(left[0],height[0])
        for i in range(1,n):
            left[i] = max(left[i-1],height[i])
        right[n-1] = max(right[n-1],height[n-1])
        for i in range(n-2,-1,-1):
            right[i] = max(right[i+1],height[i])
        res = 0
        for i in range(n):
            res += (min(left[i],right[i])-height[i])
        return res
        