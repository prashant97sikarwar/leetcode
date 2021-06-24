//Problem Link:- https://leetcode.com/problems/count-sub-islands/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool visited[501][501];
    bool flag;
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if (i < 0 || j < 0 || i >= n || j >= m || grid2[i][j] != 1 || visited[i][j]){
            return;
        }
        if (grid1[i][j] != 1){
            flag = true;
            return;
        }
        visited[i][j] = true;
        dfs(i+1,j,n,m,grid1,grid2);
        dfs(i,j+1,n,m,grid1,grid2);
        dfs(i-1,j,n,m,grid1,grid2);
        dfs(i,j-1,n,m,grid1,grid2);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        memset(visited,false,sizeof(visited));
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (!visited[i][j] && grid2[i][j] == 1){
                    flag = false;
                    dfs(i,j,n,m,grid1,grid2);
                    if (flag == false){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};