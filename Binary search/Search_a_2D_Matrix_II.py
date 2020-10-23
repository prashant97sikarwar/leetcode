#Problem Link :- https://leetcode.com/problems/search-a-2d-matrix-ii/

"""Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has 
the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
"""

class Solution:
    def searchMatrix(self, matrix, target):
        if len(matrix) == 0:
            return False
        n = len(matrix)
        i = 0
        j = len(matrix[0])-1
        while i < n and j >= 0:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                j -= 1
            elif matrix[i][j] < target:
                i  += 1
        return False