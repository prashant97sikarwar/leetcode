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