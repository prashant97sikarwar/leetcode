#Problem link :- https://leetcode.com/problems/maximal-square/

"""Given a 2D binary matrix filled with 0's and 1's, find the largest square 
containing only 1's and return its area."""

class Solution:
    def maximalSquare(self, matrix):
        if len(matrix) == 0:
            return 0

        area = -1
        n = len(matrix)
        arr = [0 for i in range(len(matrix[0]))]
        for i in range(n):
            for j in range(len(matrix[i])):
                if matrix[i][j] == '0':
                    arr[j] = 0
                if matrix[i][j] == '1':
                    arr[j] += 1  
            area = max(area,self.helper(arr))
        return area
        
    def helper(self,heights):
        if len(heights) == 0:
            return 0
        if len(heights) == 1:
            return 1 if heights[0] > 0 else 0
        res = 0
        st1 = []
        heights = [0] + heights + [0]
        for i,j in enumerate(heights):
            while st1 and heights[st1[-1]] > j:
                h = st1.pop()
                temp = min((i-st1[-1]-1),heights[h])
                res = max(res,temp*temp)
            st1.append(i)
        return res