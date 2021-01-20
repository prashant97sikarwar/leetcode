#Problem Link:- https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/

"""You are given an array rectangles where rectangles[i] = [li, wi] represents the ith 
rectangle of length li and width wi.You can cut the ith rectangle to form a square with 
a side length of k if both k <= li and k <= wi.Return the number of rectangles that can 
make a square with a side length of maxLen."""

class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        d = dict()
        for x in rectangles:
            width = min(x[0],x[1])
            if width not in d:
                d[width] = 1
            else:
                d[width] += 1
        x = max(d.keys())
        return d[x]
        

