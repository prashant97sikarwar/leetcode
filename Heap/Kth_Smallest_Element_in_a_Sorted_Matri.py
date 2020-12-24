#Problem Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

"""Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix.Note that it is the kth smallest element in 
the sorted order, not the kth distinct element. """

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        heap = []
        import heapq
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if len(heap) < k:
                    heapq.heappush(heap,-matrix[i][j])
                else:
                    if matrix[i][j] <= -heap[0]:
                        heapq.heappop(heap)
                        heapq.heappush(heap,-matrix[i][j])
        return -heap[0]
        