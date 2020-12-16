#Problem linkL:- https://leetcode.com/problems/01-matrix/

"""Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1."""

class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return matrix
        row = len(matrix)
        col = len(matrix[0])
        que = []
        for i in range(row):
            for j in range(col):
                if matrix[i][j] == 0:
                    que.append((i+1,j))
                    que.append((i-1,j))
                    que.append((i,j-1))
                    que.append((i,j+1))
        vis = [[False for i in range(col)] for i in range(row)]
        dist = 0
        while que:
            dist += 1
            for i in range(len(que)):
                node = que[0]
                x = node[0]
                y = node[1]
                que.pop(0)
                if x >= 0 and y >= 0 and x < row and y < col and vis[x][y] == False and matrix[x][y] == 1:
                    vis[x][y] = True
                    matrix[x][y] = dist
                    que.append((x-1,y))
                    que.append((x+1,y))
                    que.append((x,y-1))
                    que.append((x,y+1))
        return matrix