// Problem Link:- https://leetcode.com/problems/n-queens/

/* The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two 
queens attack each other.Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and 
'.' both indicate a queen and an empty space, respectively. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    
    bool valid(vector<string> board,int row, int col){
        for(int i=row;i>=0;i--){
            if (board[i][col] == 'Q')
                return false;
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if (board[i][j] == 'Q')
                return false;
        }
        for(int i=row,j=col;i>=0 && j<board.size();i--,j++){
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    
    void helper(vector<string>& board, int row){
        if (row >= board.size()){
            result.push_back(board);
            return;
        }
        for(int i=0;i<board.size();i++){
            if (valid(board,row,i)){
                board[row][i] = 'Q';
                helper(board,row+1);
                board[row][i] = '.';
            }
        }
    }
        
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0)
            return {{}};
        vector<string> board(n,string(n,'.'));
        helper(board,0);
        return result;
    }
};