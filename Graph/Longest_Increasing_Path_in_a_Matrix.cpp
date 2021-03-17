//problem Link:- https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

/* Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not 
move diagonally or move outside the boundary */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    bool safe(int x,int y,int n,int m){
        if (x < 0 || y < 0 || x >= n || y >= m)
            return false;
        return true;
    }
    
    int dfs(vector<vector<int>>& matrix,int i,int j,int n,int m,vector<vector<int>>& dp){
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = INT_MIN;
        for(int k=0;k<4;k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if (safe(x,y,n,m) && matrix[x][y] > matrix[i][j]){
                res = max(1 + dfs(matrix,x,y,n,m,dp),res);
            }
        }
        return dp[i][j] = max(res,1);
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mx = -1;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(matrix,i,j,n,m,dp);
                mx = max(mx,dp[i][j]);
            }
        }
        return mx;
    }
};