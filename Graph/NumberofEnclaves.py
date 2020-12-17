#Problelm Link: https://leetcode.com/problems/number-of-enclaves/

"""Given a 2D array A, each cell is 0 (representing sea) or 1 (representing land)A move 
consists of walking from one land square 4-directionally to another land square, or off 
the boundary of the grid.Return the number of land squares in the grid for which we 
cannot walk off the boundary of the grid in any number of moves."""

class Solution(object):
    def numEnclaves(self, A):
        row = len(A)
        col = len(A[0])
        
        dx = [-1,0,1,0]
        dy = [0,1,0,-1]
        
        vis = [[False for i in range(col)] for i in range(row)]
        
        def safe(x,y,row,col,A,vis):
            if x >= 0 and y >= 0 and x < row and y < col and vis[x][y] == False and A[x][y] == 1:
                return True
            return False
        
        def dfs(i,j,A,vis):
            row = len(A)
            col = len(A[0])
            vis[i][j] = True
            for k in range(4):
                if safe(i+dx[k],j+dy[k],row,col,A,vis):
                    dfs(i+dx[k],j+dy[k],A,vis)
            
        
        for i in range(row):
            if A[i][0] == 1 and vis[i][0] == False:
                dfs(i,0,A,vis)
            if A[i][col-1] == 1 and vis[i][col-1] == False:
                dfs(i,col-1,A,vis)
        
        for i in range(col):
            if A[0][i] == 1 and vis[0][i] == False:
                dfs(0,i,A,vis)
            if  A[row-1][i] == 1 and vis[row-1][i] == False:
                dfs(row-1,i,A,vis)
        
        cnt = 0
        for i in range(row):
            for j in range(col):
                if A[i][j] == 1 and vis[i][j] == False:
                    cnt += 1
        return cnt
                    