//Problem Link:- https://leetcode.com/problems/path-with-maximum-gold/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>> &grid, int row, int col) {
        if(row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0) {
            return 0;
        }
        if(grid[row][col] == 0) {
            return 0;
        }
        
        int temp = grid[row][col];
        grid[row][col] = 0;
        int ans = max(dfs(grid, row-1, col), dfs(grid, row+1, col));
        ans = max(ans, dfs(grid, row, col-1));
        ans = max(ans, dfs(grid, row, col+1));
        
        grid[row][col] = temp;
        
        return ans + temp; 
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res = max(res, dfs(grid,i,j));
            }
        }
        return res;
    }
};