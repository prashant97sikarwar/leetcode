#Problem Link:- 

"""Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded 
by 'X'.A region is captured by flipping all 'O's into 'X's in that surrounded region."""

class Solution(object):
    def solve(self, board):
        if len(board) == 0:
            return 
        n = len(board)
        m = len(board[0])
        
        def dfs(i,j,board):
            n = len(board)
            m = len(board[0])
            if i < 0 or j < 0 or i > n-1 or j > m-1:
                return 
            board[i][j] = " "
            if i > 0 and board[i-1][j] == 'O':
                dfs(i-1,j,board)
            if i < n-1 and board[i+1][j] == 'O':
                dfs(i+1,j,board)
            if j > 0 and board[i][j-1] == 'O':
                dfs(i,j-1,board)
            if j < m-1 and board[i][j+1] == 'O':
                dfs(i,j+1,board)
                
        for i in range(n):
            if board[i][0] == 'O':
                dfs(i,0,board)
            if board[i][m-1] == 'O':
                dfs(i,m-1,board)
        for i in range(m-1):
            if board[0][i] == 'O':
                dfs(0,i,board)
            if board[n-1][i] == 'O':
                dfs(n-1,i,board)
        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                if board[i][j] == " ":
                    board[i][j] = 'O'
        return board
        
        
    
            