"""Given a rows * columns matrix mat of ones and zeros, return how 
many submatrices have all ones."""


class Solution(object):
    def numSubmat(self, mat):
        n = len(mat)
        m = len(mat[0])
        arr = [[0 for i in range(m)] for i in range(n)]
        for i in range(n):
            c = 0
            for j in range(m-1,-1,-1):
                if mat[i][j] == 1:
                    c += 1
                else:
                    c =  0
                arr[i][j] = c
        res = 0
        for i in range(n):
            for j in range(m):
                x = float('inf')
                for k in range(i,n):
                    x = min(x,arr[k][j])
                    res += x
        return res
        