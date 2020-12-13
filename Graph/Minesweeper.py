#Problem Link:- https://leetcode.com/problems/minesweeper/

"""You are given a 2D char matrix representing the game board. 'M' represents an unrevealed
mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square 
that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to
'8') represents how many mines are adjacent to this revealed square, and finally 'X' 
represents a revealed mine.Now given the next click position (row and column indices) 
among all the unrevealed squares ('M' or 'E'), return the board after revealing this 
position according to the following rules:If a mine ('M') is revealed, then the game is 
over - change it to 'X'.If an empty square ('E') with no adjacent mines is revealed, then 
change it to revealed blank ('B') and all of its adjacent unrevealed squares should be 
revealed recursively.If an empty square ('E') with at least one adjacent mine is revealed, 
then change it to a digit ('1' to '8') representing the number of adjacent mines.Return 
the board when no more squares will be revealed."""

class Solution(object):
    def updateBoard(self, board, click):
        if not board:
            return board
        dx = [-1,-1,0,1,1,1,0,-1]
        dy = [0,1,1,1,0,-1,-1,-1]
        x = click[0]
        y = click[1]
                
        if board[x][y] == 'M':
            board[x][y] = 'X'
            return board
        def safe(i,j,board):
            if i >= 0 and j >= 0 and i < len(board) and j < len(board[0]):
                return True
            return False
        
        def helper(i,j,board):
            cnt = 0
            for k in range(8):
                if safe(i+dx[k],j+dy[k],board):
                    if board[i+dx[k]][j+dy[k]] == 'M':
                        cnt+=1
            return cnt
        numAdj = helper(x,y,board)
        if numAdj > 0:
            board[x][y] = str(numAdj)
        else:
            board[x][y] = 'B'
            for i in range(8):
                if safe(x+dx[i],y+dy[i],board) and board[x+dx[i]][y+dy[i]] != 'B':
                    self.updateBoard(board,[x+dx[i],y+dy[i]])
        return board