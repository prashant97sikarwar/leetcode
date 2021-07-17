//Problem Link:- https://leetcode.com/problems/critical-connections-in-a-network/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<int> graph[100005];
        int low[100005],disc[100005],vis[100005];
        vector<vector<int>> bridges;
        int timer;
        
public:
    void dfs(int cur,int par){
        low[cur] = disc[cur] = timer++;
        vis[cur] = 1;
        for(int child : graph[cur]){
            if (child == par){
                continue;
            }
            if (vis[child] == 1){
                low[cur] = min(low[cur],disc[child]);
            }
            else{
                dfs(child,cur);
                low[cur] = min(low[cur],low[child]);
                if (low[child] > disc[cur]){
                    bridges.push_back({cur,child});
                }
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        memset(low,-1,sizeof(low));
        memset(vis,0,sizeof(vis));
        memset(disc,-1,sizeof(disc));
        timer = 0;
        dfs(0,-1);
        return bridges;
    }
};