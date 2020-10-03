"""Given a board with m by n cells, each cell has an initial state live (1) or dead (0). 
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the 
following four rules (taken from the above Wikipedia article):Any live cell with fewer 
than two live neighbors dies, as if caused by under-population.Any live cell with two or 
three live neighbors lives on to the next generation.Any live cell with more than three 
live neighbors dies, as if by over-population..Any dead cell with exactly three live 
neighbors becomes a live cell, as if by reproduction.Write a function to compute the next 
state (after one update) of the board given its current state. The next state is created 
by applying the above rules simultaneously to every cell in the current state, where births 
and deaths occur simultaneously."""

class Solution(object):
    def gameOfLife(self, board):
        n = len(board)
        m = len(board[0])
        l = []
        for i in range(n):
            for j in range(m):
                cnt = self.dfs(i,j,n,m,board)
                if board[i][j] == 1 and cnt < 2:
                    l.append((i,j,0))
                if (board[i][j] == 1) and (cnt == 2 or cnt == 3):
                    l.append((i,j,1))
                if board[i][j] == 1 and cnt > 3:
                    l.append((i,j,0))
                if board[i][j] == 0 and cnt == 3:
                    l.append((i,j,1))
        for i in range(len(l)):
            board[l[i][0]][l[i][1]] = l[i][2]
        return board
    def issafe(self,i,j,n,m,board):
        if i >= 0 and j >= 0 and i < n and j < m:
            if board[i][j] == 1:
                return True
            return False

    def dfs(self,i,j,n,m,board):
        row_tag = [-1,-1,-1,0,1,1,1,0]
        col_tag = [-1,0,1,1,1,0,-1,-1]
        cnt = 0
        for k in range(8):
            if self.issafe(i+row_tag[k],j+col_tag[k],n,m,board):
                cnt += 1
        return cnt

