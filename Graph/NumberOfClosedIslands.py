#Problem Link:- https://leetcode.com/problems/number-of-closed-islands/

"""Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 
4-directionally connected group of 0s and a closed island is an island totally (all 
left, top, right, bottom) surrounded by 1s.Return the number of closed islands."""

class Solution(object):
    def closedIsland(self, grid):
        row = len(grid)
        col = len(grid[0])
        vis = [[0 for i in range(col)] for i in range(row)]
        cnt = 0
        
        dx = [-1,0,1,0]
        dy = [0,1,0,-1]
        
        def safe(x,y,vis,grid):
            if x >= 0 and y >= 0 and x < len(grid) and y < len(grid[0]) and vis[x][y] == 0 and grid[x][y] == 0:
                return True
            return False
        
        def dfs(x,y,vis,grid):
            vis[x][y] = 1
            for k in range(4):
                if safe(x+dx[k],y+dy[k],vis,grid):
                    dfs(x+dx[k],y+dy[k],vis,grid)
        
        for i in range(row):
            if vis[i][0] == 0 and grid[i][0] == 0:
                dfs(i,0,vis,grid)
            if vis[i][col-1] == 0 and grid[i][col-1] == 0:
                dfs(i,col-1,vis,grid)
        
        for i in range(col):
            if grid[0][i] == 0 and vis[0][i] == 0:
                dfs(0,i,vis,grid)
            if grid[row-1][i] == 0 and vis[row-1][i] == 0:
                dfs(row-1,i,vis,grid)
                
        for i in range(1,row-1):
            for j in range(1,col-1):
                if vis[i][j] == 0 and grid[i][j] == 0:
                    dfs(i,j,vis,grid)
                    cnt += 1
        return cnt