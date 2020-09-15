"""Given a m * n matrix of ones and zeros, return how many square 
submatrices have all ones."""


class Solution(object):
    def countSquares(self, matrix):
        n = len(matrix)
        m = len(matrix[0])
        count = 0
        for i in range(n):
            count += matrix[i][0]
        for i in range(1,m):
            count += matrix[0][i]
        for i in range(1,n):
            for j in range(1,m):
                if matrix[i][j] == 1:
                    matrix[i][j] = 1 + min(matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1])
                    count += matrix[i][j]
        return count
            