"""Given a collection of intervals, merge all overlapping intervals."""

class Solution(object):
    def merge(self, intervals):
        if len(intervals) <= 1:
            return intervals
        ans = []
        intervals.sort()
        n = len(intervals)
        r = intervals[0][1]
        l = intervals[0][0]
        for i in range(1,n):
            if intervals[i][0] <= r:
                r = max(intervals[i][1],r)
            else:
                ans.append([l,r])
                l = intervals[i][0]
                r = intervals[i][1]
        ans.append([l,r])
        return ans
            
            