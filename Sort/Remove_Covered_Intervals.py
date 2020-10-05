# Problem Link :- https://leetcode.com/problems/remove-covered-intervals/

"""Given a list of intervals, remove all intervals that are covered by another interval 
in the list.Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.
After doing so, return the number of remaining intervals."""

class Solution(object):
    def removeCoveredIntervals(self, intervals):
        n = len(intervals)
        if len(intervals) <= 1:
            return len(intervals)
        intervals.sort(key = lambda x: (x[0],-x[1]))
        maxEnd = 0
        for x in intervals:
            curEnd = x[1]
            if curEnd <= maxEnd:
                n -= 1
            maxEnd = max(maxEnd,curEnd)
        return n
        