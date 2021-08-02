//Problem Link:- https://leetcode.com/problems/making-a-large-island/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m,n;
    const int dx[4] = {-1,0,1,0};
    const int dy[4] = {0,1,0,-1};
    unordered_map<int,int> componentSize;
    void paint(int i,int j,vector<vector<int>>& grid,int color){
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1){
            return;
        }
        grid[i][j] = color;
        componentSize[color] += 1;
        for(int k=0;k<4;k++){
            paint(i+dx[k],j+dy[k],grid,color);
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int nextColor = 2;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j] == 0) continue;
                paint(i,j,grid,nextColor++);
                ans = max(ans,componentSize[nextColor-1]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j] != 0) continue;
                unordered_set<int> s;
                for(int k=0;k<4;k++){
                    int nr = i + dx[k];
                    int nc = j + dy[k];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == 0) continue;
                    s.insert(grid[nr][nc]);
                }
                int sz = 1;
                for(int colors : s){
                    sz += componentSize[colors];
                }
                ans = max(ans,sz);
            }
        }
        return ans;
    }
};