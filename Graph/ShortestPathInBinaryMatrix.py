#Problem Link : https://leetcode.com/problems/shortest-path-in-binary-matrix/

"""In an N by N square grid, each cell is either empty (0) or blocked (1).A clear path 
from top-left to bottom-right has length k if and only if it is composed of cells C_1, 
C_2, ..., C_k such that:Adjacent cells C_i and C_{i+1} are connected 8-directionally 
(ie., they are different and share an edge or corner)C_1 is at location (0, 0) (ie. has 
value grid[0][0]),C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1]).If C_i is 
located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).Return the length of the 
shortest such clear path from top-left to bottom-right.  If such a path does not exist, 
return -1."""

class Solution(object):
    def shortestPathBinaryMatrix(self, grid):
        if len(grid) == 1 and len(grid[0]) == 1:
            return 1
        
        dx = [-1,-1,0,1,1,1,0,-1]
        dy = [0,1,1,1,0,-1,-1,-1]
        row = len(grid)
        col = len(grid[0])
        
        if grid[row-1][col-1] == 1 or grid[0][0] == 1:
            return -1
        
        def safe(x,y,grid):
            if x >= 0 and y >= 0 and x < row and y < col and grid[x][y] == 0 and vis[x][y] == False:
                return True
            return False
        dist = [[100001 for i in range(col)] for i in range(row)]
        vis = [[False for i in range(col)] for i in range(row)]
        
        que = []
        que.append(((0,0),1))
        while que:
            node,d = que.pop(0)
            x = node[0]
            y = node[1]
            for i in range(8):
                if safe(x+dx[i],y+dy[i],grid):
                    dist[x+dx[i]][y+dy[i]] = min(1+d,dist[x+dx[i]][y+dy[i]])
                    vis[x+dx[i]][y+dy[i]] = True
                    que.append(((x+dx[i],y+dy[i]),dist[x+dx[i]][y+dy[i]]))
        return dist[row-1][col-1] if dist[row-1][col-1] < 100001 else -1
