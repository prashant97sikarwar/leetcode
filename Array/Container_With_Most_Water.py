# Problem Link :- https://leetcode.com/problems/container-with-most-water/

"""Given n non-negative integers a1, a2, ..., an , where each represents a point at 
coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the 
line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis 
forms a container, such that the container contains the most water."""

class Solution(object):
    def maxArea(self, height):
        n = len(height)
        l = 0
        r = n-1
        area = 0
        while l < r:
            area = max(area,min(height[r],height[l])*(r-l))
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
        return area
    