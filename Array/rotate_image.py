""" You are given an n x n 2D matrix representing an image, rotate the 
image by 90 degrees (clockwise).You have to rotate the image in-place, 
which means you have to modify the input 2D matrix directly. DO NOT 
allocate another 2D matrix and do the rotation. """

class Solution(object):
    def rotate(self, matrix):
        n = len(matrix)
        for i in range(n):
            for j in range(i,n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        for i in range(n):
            l = 0
            r = n-1
            while  l <= r:
                matrix[i][l],matrix[i][r] = matrix[i][r], matrix[i][l]
                l += 1
                r -= 1
        return matrix
                