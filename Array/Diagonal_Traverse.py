"""Given a matrix of M x N elements (M rows, N columns), return all 
elements of the matrix in diagonal order as shown in the below image."""

class Solution(object):
    def findDiagonalOrder(self, matrix):
        if not matrix:
            return []
        n = len(matrix)
        m = len(matrix[0])
        res, inter = [], []
        for d in range(n+m-1):
            inter = []
            r,c = 0 if d < m else d-m+1,d if d < m else m-1
            while r < n and c > -1:
                inter.append(matrix[r][c])
                r += 1
                c -= 1
            if d % 2 == 0:
                res.extend(inter[::-1])
            else:
                res.extend(inter)
        return res