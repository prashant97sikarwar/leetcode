//Problem Link:- https://leetcode.com/problems/pacific-atlantic-water-flow/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    void dfs(int i,int j,set<pair<int,int>>& vis,vector<vector<int>>& mat,int prev){
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || vis.count({i,j}) || mat[i][j] < prev){
            return;
        }
        vis.insert({i,j});
        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            dfs(nx,ny,vis,mat,mat[i][j]);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        const int rows = mat.size();
        const int cols = mat[0].size();
        
        set<pair<int,int>> pac, atl;
        
        for(int c=0;c<cols;c++){
            dfs(0,c,pac,mat,mat[0][c]);
            dfs(rows-1,c,atl,mat,mat[rows-1][c]);
        }
        
        for(int r=0;r<rows;r++){
            dfs(r,0,pac,mat,mat[r][0]);
            dfs(r,cols-1,atl,mat,mat[r][cols-1]);
        }
        vector<vector<int>> result;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if (pac.count({r,c}) && atl.count({r,c})){
                    result.push_back({r,c});
                }
            }
        }
        return result;
    }
};