#Problem Link :- https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

"""Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix."""

class Solution(object):
    def kthSmallest(self, matrix, k):
        import heapq
        heap = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if len(heap) < k:
                    heapq.heappush(heap,-1 * matrix[i][j])
                elif -1 * matrix[i][j] > heap[0]:
                    heapq.heapreplace(heap,-1*matrix[i][j])
        return abs(heapq.heappop(heap)) if heap[0] < 0 else -1 * heapq.heappop(heap)