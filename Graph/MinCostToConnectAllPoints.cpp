//Problem Link:- https://leetcode.com/problems/min-cost-to-connect-all-points/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    vector<pair<int,int>> graph[1003];
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int sz = points.size();
        for(int i=0;i<sz;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1;j<sz;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x2-x1) + abs(y2-y1);
                graph[i].push_back({j,dist});
                graph[j].push_back({i,dist});
            }
        }
        vector<int> vis(sz+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int res = 0;
        while (!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int to = node.second;
            int weight = node.first;
            if (vis[to] == 1){
                continue;
            }
            res += weight;
            vis[to] = 1;
            for(auto child : graph[to]){
                if (vis[child.first] == 0){
                    pq.push({child.second,child.first});
                }
            }
        }
        return res;
    }
};