#Problem Link : https://leetcode.com/problems/max-area-of-island/

"""Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's 
(representing land) connected 4-directionally (horizontal or vertical.) You may assume 
all four edges of the grid are surrounded by water."""

class Solution(object):
    def maxAreaOfIsland(self, grid):
        if len(grid) == 0:
            return 0
        
        row = len(grid)
        col = len(grid[0])
        
        vis = [[0 for i in range(col)] for i in range(row)]
        mx = 0
        
        dx = [-1,0,1,0]
        dy = [0,1,0,-1]
        
        def safe(x,y,vis,grid):
            if x >= 0 and y >= 0 and x < len(grid) and y < len(grid[0]) and vis[x][y] == 0 and grid[x][y] == 1:
                return True
            return False
        
        def dfs(x,y,vis,grid,area):
            vis[x][y] = 1
            area[0] += 1
            for k in range(4):
                if safe(x+dx[k],y+dy[k],vis,grid):
                    dfs(x+dx[k],y+dy[k],vis,grid,area)
        
        for i in range(row):
            for j in range(col):
                if vis[i][j] == 0 and grid[i][j] == 1:
                    area = [0]
                    dfs(i,j,vis,grid,area)
                    mx = max(area[0],mx)
        return mx