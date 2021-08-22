//Problem Link:- https://leetcode.com/problems/shortest-path-to-get-all-keys/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    bool valid(int x, int y,vector<string>& grid){
        if (x < 0 || y < 0 || x >= grid.size() ||  y >= grid[0].size()){
            return false;
        }
        return true;
    }
    
    int shortestPathAllKeys(vector<string>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        
        int srcx, srcy;
        int target = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j] == '@'){
                    srcx = i;
                    srcy = j;
                    grid[i][j] = '.';
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z'){
                    int key = grid[i][j] -'a';
                    target = target | (1 << key);
                }
            }
        }
        queue<vector<int>> pq;
        pq.push({srcx,srcy,0,target});
        set<vector<int>> vis;
        vis.insert({srcx,srcy,0,target});
        int step = 0;
        while (!pq.empty()){
            int sz = pq.size();
            while (sz--){
                auto node = pq.front();
                pq.pop();
                int i = node[0], j = node[1], key = node[2], unlocked = node[3];
                
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    
                    if (valid(nx,ny,grid)){
                        if (grid[nx][ny] == '.' && vis.count({nx,ny,key,unlocked}) == 0){
                            pq.push({nx,ny,key,unlocked});
                            vis.insert({nx,ny,key,unlocked});
                        }
                        if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z'){
                            int newkeys = grid[nx][ny] - 'a';
                            newkeys = key | (1 << newkeys);
                            if (newkeys == target){
                                return step+1;
                            }
                            if (vis.count({nx,ny,newkeys,unlocked}) == 0){
                                pq.push({nx,ny,newkeys,unlocked});
                                vis.insert({nx,ny,newkeys,unlocked});
                            }
                        }
                        else if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z'){
                            int neededKey = grid[nx][ny] - 'A';
                            if ((key >> neededKey) & 1){
                                int new_unlocked = unlocked & ~(1 << neededKey);
                                if (vis.count({nx,ny,key,new_unlocked}) == 0){
                                    pq.push({nx,ny,key,new_unlocked});
                                    vis.insert({nx,ny,key,new_unlocked});
                                }
                            }
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};