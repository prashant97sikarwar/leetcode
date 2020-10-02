"""Given a matrix of m x n elements (m rows, n columns), return all elements 
of the matrix in spiral order."""


class Solution(object):
    def spiralOrder(self, matrix):
        if len(matrix) == 0:
            return 
        if len(matrix) == 1:
            return matrix[0]
        n = len(matrix)
        m = len(matrix[0])
        i = 0
        j = 0
        k = n-1
        l = m-1
        ans = []
        while i <= k and j <= l:
            for p in range(j,l+1):
                ans.append(matrix[i][p])
            i += 1
            for q in range(i,k+1):
                ans.append(matrix[q][l])
            l -= 1
            if i <= k:
                for r in range(l,j-1,-1):
                    ans.append(matrix[k][r])
                k -= 1
            if j <= l:
                for s in range(k,i-1,-1):
                    ans.append(matrix[s][j])
                j += 1
        return ans