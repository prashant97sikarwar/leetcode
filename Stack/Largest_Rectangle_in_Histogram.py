# Problem Link :- https://leetcode.com/problems/largest-rectangle-in-histogram/

"""Given n non-negative integers representing the histogram's bar height where 
the width of each bar is 1, find the area of largest rectangle in the histogram."""

class Solution(object):
    def largestRectangleArea(self, heights):
        if len(heights) == 0:
            return 0
        if len(heights) == 1:
            return heights[0]
        res = 0
        st1 = []
        heights = [0] + heights + [0]
        for i,j in enumerate(heights):
            while st1 and heights[st1[-1]] > j:
                h = st1.pop()
                res = max(res,(i-st1[-1]-1)*heights[h])
            st1.append(i)
        return res