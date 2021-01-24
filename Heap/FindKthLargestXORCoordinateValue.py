#Problem Link:- https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/

"""You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also 
given an integer k.The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j]
where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).Find the kth largest value (1-indexed) 
of all the coordinates of matrix."""

class Solution(object):
    def kthLargestValue(self, matrix, k):
        import heapq
        for i in range(1,len(matrix)):
            matrix[i][0] ^= matrix[i-1][0]
        for i in range(1,len(matrix[0])):
            matrix[0][i] ^= matrix[0][i-1]
            
        for i in range(1,len(matrix)):
            for j in range(1,len(matrix[0])):
                matrix[i][j] ^= matrix[i-1][j] ^ matrix[i][j-1] ^ matrix[i-1][j-1]
        
        heap = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if len(heap) < k:
                    heapq.heappush(heap,matrix[i][j])
                elif heap[0] < matrix[i][j]:
                    heapq.heappop(heap)
                    heapq.heappush(heap,matrix[i][j])
        return heap[0]