# Problem Link :- https://leetcode.com/problems/word-search/

"""Given a 2D board and a word, find if the word exists in the grid.The word can be 
constructed from letters of sequentially adjacent cell, where "adjacent" cells are 
those horizontally or vertically neighboring. The same letter cell may not be used 
more than once."""

class Solution(object):
    def exist(self, board, word):
        n = len(board)
        m = len(board[0])
        for i in range(n):
            for j in range(m):
                if board[i][j] == word[0] and self.dfs(board,i,j,0,word):
                    return True
        return False
    
    def dfs(self,board,i,j,count,word):
        n = len(board)
        m = len(board[0])
        if count == len(word):
            return True
        if i < 0 or i >= n or j < 0 or j >= m or board[i][j] != word[count]:
            return False
        temp = board[i][j]
        board[i][j] = " "
        flag = self.dfs(board,i+1,j,count + 1,word) or self.dfs(board,i-1,j,count+1,word) or self.dfs(board,i,j+1,count+1,word) or self.dfs(board,i,j-1,count+1,word)
        board[i][j] = temp
        return flag
        
        