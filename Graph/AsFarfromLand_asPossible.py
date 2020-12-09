#Problem Link : https://leetcode.com/problems/as-far-from-land-as-possible/

"""Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 
represents land, find a water cell such that its distance to the nearest land cell is 
maximized, and return the distance. If no land or water exists in the grid, return -1.
The distance used in this problem is the Manhattan distance: the distance between two 
cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|."""

class Solution(object):
    def maxDistance(self, grid):
        if len(grid) == 0 or len(grid[0]) == 0:
            return -1
        que = collections.deque()
        dx = [-1,0,1,0]
        dy = [0,1,0,-1]
        mx = -1
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    que.append([(i,j),0])
        while que:
            temp = que.popleft()
            x,y = temp[0]
            d = temp[1]
            mx = max(mx,d)
            for i in range(4):
                xx = x + dx[i]
                yy = y + dy[i]
                if xx < 0 or xx >= len(grid) or yy < 0 or yy >= len(grid[0]):
                    continue
                if grid[xx][yy] == 0:
                    grid[xx][yy] = 1 + d
                    que.append([(xx,yy),1+d])
        return mx or -1