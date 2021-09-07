//Problem Link:- https://leetcode.com/problems/trapping-rain-water-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
public:
    int trapRainWater(vector<vector<int>>& grid) {
        const int row = grid.size();
        const int col = grid[0].size();
        
        vector<vector<bool>> vis(row,vector<bool> (col,false));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if (i == 0 || j == 0 || i == row-1 || j == col-1){
                    pq.push({grid[i][j],{i,j}});
                    vis[i][j] = true;
                }
            }
        }
        
        int result = 0,minHeight = 0;
        while (!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int height = node.first;
            int x = node.second.first, y = node.second.second;
            minHeight = max(minHeight, height);
            
            for(int k=0;k<4;k++){
                int nr = x + dx[k];
                int nc = y + dy[k];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && vis[nr][nc] == false){
                    pq.push({grid[nr][nc],{nr,nc}});
                    vis[nr][nc] = true;
                    if (grid[nr][nc] < minHeight){
                        result += (minHeight - grid[nr][nc]);   
                    }
                }
            }
        }
        return result;
    }
};