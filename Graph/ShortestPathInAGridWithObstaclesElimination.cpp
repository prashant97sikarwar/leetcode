//Problem Link:- https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    int m;
    int dp[45][45][1700];
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
public:
    const int MAX = 1e9;
    
    int helper(vector<vector<int>>& grid,int k, int i, int j){
        if (grid[i][j] < 0){
            return MAX;
        }
        if (i == n-1 && j == m-1 && k >= 0){
            if (grid[i][j] == 0){
                return 0;
            }
            k--;
            if (k >= 0){
                return 0;
            }
            return MAX;
        }
        if (dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        if (grid[i][j] == 1){
            k--;
        }
        
        if (k < 0){
            return MAX;
        }
        int temp = grid[i][j];
        grid[i][j] = -1;
        
        int result = MAX;
        if(i+1 < n)
            result = 1 + helper(grid, k, i+1, j);
        
        
        if(i-1 >= 0)
            result = min(result, 1 + helper(grid, k, i-1, j));
        
        if(j+1 < m)
            result = min(result, 1 + helper(grid, k, i, j+1));
        
        if(j-1 >= 0)
            result = min(result, 1 + helper(grid, k, i, j-1));
        
        grid[i][j] = temp;
        return dp[i][j][k] = result;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        
        memset(dp,-1,sizeof(dp));
        int res = helper(grid,k,0,0);
        if (res < MAX){
            return res;
        }
        return -1;
    }
};