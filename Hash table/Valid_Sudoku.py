# Problem Link :- https://leetcode.com/problems/valid-sudoku/
"""Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated"""

class Solution(object):
    def isValidSudoku(self, board):
        def check_repetition(arr):
            hashmap = {}
            
            for num in arr:
                if num == ".":
                    continue
                    
                hashmap[num] = hashmap.get(num, 0) + 1
                
                if hashmap[num] > 1:
                    return True
            
            return False
        for row in board:
            if check_repetition(row):
                return False
        for i in range(len(board[0])):
            column = []
            for j in range(len(board)):
                column.append(board[j][i])
                
            if check_repetition(column):
                return False
        for i in range(0, len(board), 3):
            for j in range(0, len(board[0]), 3):
                new_row = []
                for k in range(i, i+3):
                    for l in range(j, j+3):
                        new_row.append(board[k][l])
                        
                if check_repetition(new_row):
                    return False
                
            
        return True