//Problem Link:- https://leetcode.com/problems/n-queens-ii/

/* The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that 
no two queens attack each other.Given an integer n, return the number of distinct solutions 
to the n-queens puzzle. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count;
    bool isvalid(vector<string>& queen,int r, int c){
        for(int i=r;i>=0;--i){
            if (queen[i][c] == 'Q')
                return false;
        }
        for(int i=r,j=c;i>=0 && j>=0;--i,--j){
            if (queen[i][j] == 'Q')
                return false;
        }
        for(int i=r,j=c;i>=0 && j<queen.size();--i,++j){
            if (queen[i][j] == 'Q')
                return false;
        }
        return true;
    }
    
    void helper(vector<string>& queen, int row){
        if (row >= queen.size()){
            count++;
            return;
        }
        for(int col=0;col < queen.size();col++){
            if (isvalid(queen,row,col)){
                queen[row][col] = 'Q';
                helper(queen,row+1);
                queen[row][col] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<string> queen(n,string(n,'.'));
        helper(queen,0);
        return count;
        
    }
};

