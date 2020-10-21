# Problem Link :- https://leetcode.com/problems/number-of-islands/

"""Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or 
vertically. You may assume all four edges of the grid are all surrounded by water."""

class Solution(object):
    def numIslands(self, grid):
        n = len(grid)
        m = len(grid[0])
        visited = [[False for i in range(m)] for i in range(n)]
        count = 0
        for i in range(n):
            for j in range(m):
                if visited[i][j] == False and grid[i][j] == '1':
                    self.dfs(i,j,n,m,grid,visited)
                    count += 1
        return count
    
    def isSafe(self,i,j,n,m,grid,visited):
        if i >= 0 and j >= 0 and i < n and j < m and visited[i][j] == False and grid[i][j] == '1':
            return True
        return False
    
    def dfs(self,i,j,n,m,grid,visited):
        row = [-1,0,1,0]
        col = [0,1,0,-1]
        visited[i][j] = True
        for k in range(4):
            if self.isSafe(i+row[k],j+col[k],n,m,grid,visited):
                self.dfs(i+row[k],j+col[k],n,m,grid,visited)
                
        
        