class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        d = dict()
        for i in range(len(intervals)):
            d[tuple(intervals[i])] = i
        intervals.sort(key = lambda x:x[0])
        res = [0]*len(intervals)
        for i in range(len(intervals)):
            start, end = intervals[i]
            ind = self.search(end,i+1,len(intervals),intervals)
            if ind == len(intervals):
                res[d[tuple(intervals[i])]] = -1
            else:
                res[d[tuple(intervals[i])]] = d[tuple(intervals[ind])]
        return res
            
    def search(self,target,l,r,intervals):
        while l < r:
            mid = l + (r-l)//2
            if intervals[mid][0] >= target:
                r = mid
            else:
                l = mid + 1
        return l