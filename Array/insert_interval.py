# Problem Link :- https://leetcode.com/problems/insert-interval/

"""Given a set of non-overlapping intervals, insert a new interval into the intervals 
(merge if necessary).You may assume that the intervals were initially sorted according
to their start times."""

class Solution(object):
    def insert(self, intervals, newInterval):
        intervals.append(newInterval)
        intervals.sort()
        return self.mergeInterval(intervals)
        
    def mergeInterval(self,intervals):
        if len(intervals) <= 1:
            return intervals
        ans = []
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