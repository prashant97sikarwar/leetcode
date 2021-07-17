//Problem Link:- https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
class Solution {
    bool visited[32][32];
    int low[32][32], disc[32][32];
    int timer;
    int ap;
    
public:
    bool valid(int x,int y,vector<vector<int>>& grid, int n,int m){
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0){
            return false;
        }
        return true;
    }
    
    void dfs(int i,int j,vector<vector<int>>& grid,int n,int m,int px,int py){
        low[i][j] = disc[i][j] = timer++;
        visited[i][j] = true;
        int no_child = 0;
        for(int k=0;k<4;k++){
            int xc = i + dx[k];
            int yc = j + dy[k];
            if (valid(xc,yc,grid,n,m)){
                if (xc == px && yc == py){
                    continue;
                }
                if (visited[xc][yc] == true){
                    low[i][j] = min(low[i][j],disc[xc][yc]);
                }
                else{
                    dfs(xc,yc,grid,n,m,i,j);
                    no_child++;
                    low[i][j] = min(low[i][j],low[xc][yc]);
                    if (low[xc][yc] >= disc[i][j] && px != -1 && py != -1){
                        ap++;
                    }
                }
            }
        }
        if (px == -1 && py == -1 && no_child >= 2){
            ap++;
        }
        return;
    }
    
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(visited,false,sizeof(visited));
        memset(low,-1,sizeof(low));
        memset(disc,-1,sizeof(disc));
        int cnt = 0;
        timer = 0,ap = 0;
        int ones = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j] == 1){
                    ones++;
                }
            }
        }
        if (ones == 0){
            return 0;
        }
        if (ones == 1){
            return 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j] && !visited[i][j]){
                    dfs(i,j,grid,n,m,-1,-1);
                    cnt++;
                    if (cnt > 1){
                        return 0;
                    }
                }
            }
        }
        if (ap > 0){
            return 1;
        }
        return 2;
    }
};