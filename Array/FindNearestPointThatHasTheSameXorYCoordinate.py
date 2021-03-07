# Problem Link:- https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

"""You are given two integers, x and y, which represent your current location on a Cartesian grid: 
(x, y). You are also given an array points where each points[i] = [ai, bi] represents that a point 
xists at (ai, bi). A point is valid if it shares the same x-coordinate or the same y-coordinate as 
your location.Return the index (0-indexed) of the valid point with the smallest Manhattan distance
from your current location. If there are multiple, return the valid point with the smallest index. 
If there are no valid points, return -1."""

class Solution(object):
    def nearestValidPoint(self, x, y, points):
        ans = -1
        mn = float("inf")
        for i in range(len(points)):
            u = points[i][0]
            v = points[i][1]
            if u == x or v == y:
                dist = abs(u-x) + abs(v-y)
                if dist < mn:
                    ans = i
                    mn = dist
                elif dist == mn:
                    ans = min(ans,i)
            else:
                continue
        return ans
