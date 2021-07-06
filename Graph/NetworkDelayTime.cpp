//Problem Link:- https://leetcode.com/problems/network-delay-time/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<pair<int,int>> graph[105];
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];
            graph[u].push_back({v,t});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        while (!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int d = node.first;
            int u = node.second;
            for(auto nie : graph[u]){
                int child = nie.first;
                int w = nie.second;
                if (dist[child] > dist[u] + w){
                    dist[child] = dist[u] + w;
                    pq.push({dist[child],child});
                }
            }
        }
        int res = *max_element(dist.begin()+1,dist.end());
        return (res == INT_MAX ? -1 : res);
    }
};