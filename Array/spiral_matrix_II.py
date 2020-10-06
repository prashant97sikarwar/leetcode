# Problem Link :- https://leetcode.com/problems/spiral-matrix-ii/

"""Given a positive integer n, generate a square matrix filled with elements from 1 to n2 
in spiral order."""

class Solution(object):
    def generateMatrix(self, n):
        res = [[0 for i in range(n)] for i in range(n)]
        cnt = 1
        i = 0
        k = n-1
        j = 0
        l = n-1
        while i <= k and j <= l:
            for p in range(j,l+1):
                res[i][p] = cnt
                cnt += 1
            i += 1
            for q in range(i,k+1):
                res[q][l] = cnt
                cnt += 1
            l -= 1
            if i <= k:
                for r in range(l,j-1,-1):
                    res[k][r] = cnt
                    cnt += 1
                k -= 1
            if j <= l:
                for s in range(k,i-1,-1):
                    res[s][j] = cnt
                    cnt += 1
                j += 1
        return res
        