#Problem Link : https://leetcode.com/problems/coloring-a-border/

"""Given a 2-dimensional grid of integers, each value in the grid represents the color 
of the grid square at that location.Two squares belong to the same connected component 
if and only if they have the same color and are next to each other in any of the 4 
directions.The border of a connected component is all the squares in the connected 
component that are either 4-directionally adjacent to a square not in the component, 
or on the boundary of the grid (the first or last row or column).Given a square at 
location (r0, c0) in the grid and a color, color the border of the connected component 
of that square with the given color, and return the final grid."""

class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        if len(grid) == 0:
            return 
        
        row = len(grid)
        col = len(grid[0])
        
        ans = [[0 for i in range(col)] for i in range(row)]
        for i in range(row):
            for j in range(col):
                ans[i][j] = grid[i][j]
        
        vis = [[0 for i in range(col)] for i in range(row)]
        dx = [-1,0,1,0]
        dy = [0,1,0,-1]
        
        def safe(x,y,vis,grid,dep):
            if x >= 0 and y >= 0 and x < len(grid) and y < len(grid[0]) and grid[x][y] == dep:
                return True
            return False
        
        stack = [(r0,c0)]
        while stack:
            x,y = stack.pop()
            vis[x][y] = 1
            dep = grid[x][y]
            for i in range(4):
                if safe(x+dx[i],y+dy[i],vis,grid,dep):
                    if vis[x+dx[i]][y+dy[i]] == 0:
                        stack.append((x+dx[i],y+dy[i]))
                else:
                    ans[x][y] = color
        return ans