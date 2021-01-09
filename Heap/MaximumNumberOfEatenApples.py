#Problem Link:- https://leetcode.com/problems/maximum-number-of-eaten-apples/

"""There is a special kind of apple tree that grows apples every day for n days. On the ith 
day, the tree grows apples[i] apples that will rot after days[i] days, that is on day 
i + days[i] the apples will be rotten and cannot be eaten. On some days, the apple tree 
does not grow any apples, which are denoted by apples[i] == 0 and days[i] == 0.You decided 
to eat at most one apple a day (to keep the doctors away). Note that you can keep eating 
after the first n days.Given two integer arrays days and apples of length n, return the 
maximum number of apples you can eat."""

class Solution(object):
    def eatenApples(self, apples, days):
        import heapq
        heap = []
        res = 0 
        i = 0
        n= len(apples)
        while True:
            if i < n:
                heapq.heappush(heap,(i+days[i],apples[i]))
            while heap and heap[0][0] <= i:
                heapq.heappop(heap)
            if heap:
                limit,app = heapq.heappop(heap)
                res += 1
                if app > 1:
                    heapq.heappush(heap,(limit,app-1))
            if not heap and i > n:
                break
            i+=1
        return res
                    