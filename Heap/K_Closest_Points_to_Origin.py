#Problem Link:- https://leetcode.com/problems/k-closest-points-to-origin/

"""We have a list of points on the plane.  Find the K closest points to the origin 
(0, 0).(Here, the distance between two points on a plane is the Euclidean distance.)
You may return the answer in any order.  The answer is guaranteed to be unique (except 
for the order that it is in.)"""

class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        import math
        import heapq
        n = len(points)
        if n == 1:
            return points[0]
        heap = []
        ans = []
        for i in range(n):
            x = points[i][0]
            y = points[i][1]
            dist = math.sqrt(x*x + y*y)
            heapq.heappush(heap,(dist,i))
        for i in range(K):
            d,ind = heapq.heappop(heap)
            ans.append(points[ind])
        return ans