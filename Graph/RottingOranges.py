#Problem Link:- https://leetcode.com/problems/rotting-oranges/

"""In a given grid, each cell can have one of three values:the value 0 representing an 
empty cell;the value 1 representing a fresh orange;the value 2 representing a rotten 
orange.Every minute, any fresh orange that is adjacent (4-directionally) to a rotten 
orange becomes rotten.Return the minimum number of minutes that must elapse until no 
cell has a fresh orange.  If this is impossible, return -1 instead."""

class Solution(object):
    def orangesRotting(self, grid):
        rottenQueue = []
        countOranges = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]!=0:
                    countOranges += 1
                if grid[i][j] == 2:
                    rottenQueue.append((i,j))
                    
        time = 0
        rottenQueue.append(None)
        while len(rottenQueue):
            temp = rottenQueue.pop(0)
            if temp is None:
                if len(rottenQueue) != 0:
                    time += 1
                    rottenQueue.append(None)
            else:
                countOranges -= 1
                self.turnSurrounding(temp[0],temp[1],rottenQueue,grid)
        return time if countOranges == 0 else -1
                    
    def turnSurrounding(self, x, y, rottenQueue, grid):
	if (x-1)>=0 and grid[x-1][y]==1:
		grid[x-1][y] = 2
		rottenQueue.append((x-1, y))
	
	if (x+1)<len(grid) and grid[x+1][y]==1:
		grid[x+1][y] = 2
		rottenQueue.append((x+1, y))
		
	if (y-1)>=0 and grid[x][y-1]==1:
		grid[x][y-1] = 2
		rottenQueue.append((x, y-1))
		
	if (y+1)<len(grid[0]) and grid[x][y+1]==1:
		grid[x][y+1] = 2
		rottenQueue.append((x, y+1))



 