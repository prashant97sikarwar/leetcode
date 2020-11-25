#Problem link;- https://leetcode.com/problems/count-servers-that-communicate/

"""You are given a map of a server center, represented as a m * n integer matrix grid, 
where 1 means that on that cell there is a server and 0 means that it is no server. 
Two servers are said to communicate if they are on the same row or on the same column.
Return the number of servers that communicate with any other server."""

class Solution(object):
    def countServers(self, grid):
        row = len(grid)
        col = len(grid[0])
        res = 0
        for i in range(row):
            c = 0
            for j in range(col):
                if grid[i][j] == 1:
                    c += 1
            if c > 1:
                res += c
                grid[i] = [-x for x in grid[i]]

        for i in range(col):
            c,d = 0,0
            for j in range(row):
                if grid[j][i]:
                    c += 1
                if grid[j][i] < 0:
                    d += 1
            if c > 1:
                res += c-d
        return res