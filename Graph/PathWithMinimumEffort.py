#Problem Link :- https://leetcode.com/problems/path-with-minimum-effort/

"""You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of 
size rows x columns, where heights[row][col] represents the height of cell (row, col). 
You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right 
cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and 
you wish to find a route that requires the minimum effort.A route's effort is the maximum 
absolute difference in heights between two consecutive cells of the route.Return the 
minimum effort required to travel from the top-left cell to the bottom-right cell."""

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        row = len(heights)
        col = len(heights[0])
        import heapq
        minHeap = []
        minHeap.append((0,0,0))
        arr = [[float("inf") for i in range(col)]for j in range(row)]
        arr[0][0] = 0
        direction = [(1,0),(0,-1),(-1,0),(0,1)]
        while minHeap:
            temp = heappop(minHeap)
            mx,x,y = temp[0],temp[1],temp[2]
            for i in range(4):
                nx = x + direction[i][0]
                ny = y + direction[i][1]
                if nx >= 0 and ny >= 0 and nx < row and ny < col:
                    diff = max(mx,abs(heights[nx][ny] - heights[x][y]))
                    if diff < arr[nx][ny]:
                        arr[nx][ny] = diff
                        heappush(minHeap,(diff,nx,ny))
        return  arr[row-1][col-1]
                    