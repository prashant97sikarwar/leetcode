# Problem Link :- https://leetcode.com/problems/set-matrix-zeroes/

"""Given an m x n matrix. If an element is 0, set its entire row and 
column to 0. Do it in-place."""

class Solution(object):
    def setZeroes(self, matrix):
        n = len(matrix)
        m = len(matrix[0])
        row = []
        col = []
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    row.append(i)
                    col.append(j)
        for i in range(len(row)):
            r = row[i]
            for j in range(m):
                matrix[r][j] = 0
        for i in range(len(col)):
            c  = col[i]
            for j in range(n):
                matrix[j][c] = 0
        return matrix