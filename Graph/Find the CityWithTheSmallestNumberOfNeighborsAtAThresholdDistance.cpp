//Problem Link:- https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<int>> dist(n,vector<int> (n,1e9));
        for(int i=0;i<edges.size();i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int w = edges[i][2];
            dist[x][y] = w;
            dist[y][x] = w;
        }
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if (dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int res = -1;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if (dist[i][j] <= threshold){
                    cnt++;
                }
            }
            if (cnt <= ans){
                ans = cnt;
                res = i;
            }
        }
        return res;
    }
};