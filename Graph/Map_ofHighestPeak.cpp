//Problem Link:- https://leetcode.com/problems/map-of-highest-peak/

/* You are given an integer matrix isWater of size m x n that represents a map of land and water 
cells.
1.If isWater[i][j] == 0, cell (i, j) is a land cell.
2.If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:
1.The height of each cell must be non-negative.
2.If the cell is a water cell, its height must be 0.
3.Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent 
    to another cell if the former is directly north, east, south, or west of the latter (i.e., 
    their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.
Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there 
are multiple solutions, return any of them. */ 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(int x, int y, int m, int n){
        if (x >= 0 && y >= 0 && x < n && y < m)
            return true;
        return false;
    }
        
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        queue<pair<int,int>> pq;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (mat[i][j] == 1){
                    pq.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while (!pq.empty()){
            for(int cnt = pq.size(); cnt > 0; --cnt){
                int x = pq.front().first;
                int y = pq.front().second;
                pq.pop();
                for(int i=0;i<4;i++){
                    if (helper(x+dx[i], y+dy[i], m, n) && ans[x+dx[i]][y+dy[i]] == -1){
                        ans[x+dx[i]][y+dy[i]] = 1 + ans[x][y];
                        pq.push({x+dx[i],y+dy[i]});
                    }
                    else
                        continue;
                }
            }
        }
        return ans;
    }
};