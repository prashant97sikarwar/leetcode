#Problem Link:- https://leetcode.com/problems/largest-submatrix-with-rearrangements/

"""You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the 
columns of the matrix in any order.Return the area of the largest submatrix within matrix 
where every element of the submatrix is 1 after reordering the columns optimally."""

class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        m = len(matrix[0])
        for i in range(1,n):
            for j in range(m):
                matrix[i][j] += matrix[i-1][j] if matrix[i][j] else 0
                
        ans = 0
        for i in range(n):
            matrix[i].sort(reverse = True)
            for j in range(m):
                ans = max(ans,(j+1) * matrix[i][j])
        return ans
                
        