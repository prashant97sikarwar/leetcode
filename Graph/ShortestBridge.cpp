//Problem Link:- https://leetcode.com/problems/shortest-bridge/

/* In a given 2D binary array A, there are two islands.  (An island is a 4-directionally 
connected group of 1s not connected to any other 1s.)Now, we may change 0s to 1s so as to 
connect the two islands together to form 1 island.Return the smallest number of 0s that must 
be flipped. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool visited[105][105];
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    bool safe(int row,int col,int n, int m,vector<vector<int>> arr){
        if (row < 0 || col < 0 || row >= n || col >= m || arr[row][col] == 2 || visited[row][col] == true)
            return false;
        return true;
    }
    
    void dfs(int i,int j,int n,int m,vector<vector<int>>& arr,queue<pair<int,int>>& Q){
        if (i < 0 || j < 0 || i >= n || j >= m || arr[i][j] != 1 || visited[i][j] == true)
            return;
        arr[i][j] = 2;
        Q.push({i,j});
        visited[i][j] = true;
        for(int k=0;k<4;k++){
            int row = i + dx[k];
            int col = j + dy[k];
            dfs(row,col,n,m,arr,Q);
        }
        
    }
    
    int shortestBridge(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr.size();
        int count = 0;
        queue<pair<int,int>> Q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (arr[i][j] == 1){
                    if (count == 0){
                        dfs(i,j,n,m,arr,Q);
                        count++;
                    }
                }
            }
        }
        int step = 0;
        while (!Q.empty()){
            int sz = Q.size();
            while (sz--){
                auto node = Q.front();
                int x = node.first;
                int y = node.second;
                Q.pop();
                for(int k=0;k<4;k++){
                    int newrow = x + dx[k];
                    int newcol = y + dy[k];
                    if (safe(newrow,newcol,n,m,arr)){
                        if (arr[newrow][newcol] == 1){
                            return step;
                        }
                        else{
                            arr[newrow][newcol] = 2;
                            Q.push({newrow,newcol});
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};