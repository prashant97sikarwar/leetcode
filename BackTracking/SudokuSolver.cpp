#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isValid(vector<vector<char>>& board,int r, int c, char ch){
        for(int i=0;i<9;i++){
            if (board[i][c] == ch)
                return false;
            if (board[r][i] == ch)
                return false;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==ch)
                return false;
        }
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board){
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (board[i][j] == '.'){
                    for(char c='1';c <= '9';c++){
                        if (isValid(board,i,j,c)){
                            board[i][j] = c;
                            if (backtrack(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};