//Problem Link:- https://leetcode.com/problems/shortest-path-with-alternating-colors/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        unordered_map<int,vector<pair<int,char>>> graph;
        for(auto x: red_edges){
            graph[x[0]].push_back({x[1],'R'});
        }
        for(auto x: blue_edges){
            graph[x[0]].push_back({x[1],'B'});
        }
        queue<pair<int,char>> pq;
        for(auto x:graph[0]){
            pq.push(x);
        }
        int level = 0;
        vector<int> dist(n,-1);
        dist[0] = 0;
        set<pair<int,char>> visited;
        visited.insert({0,'R'});
        visited.insert({0,'B'});
        while(!pq.empty()){
            int sz = pq.size();
            level++;
            while(sz--){
                auto pr = pq.front();
                pq.pop();
                int node = pr.first;
                char color = pr.second;
                if (dist[node] == -1)
                    dist[node] = level;
                else
                    dist[node] = min(level,dist[node]);
                for(auto x:graph[node]){
                    int nxt = x.first;
                    char nxtcol = x.second;
                    if (nxtcol != color && visited.find({nxt,nxtcol}) == visited.end()){
                        visited.insert({nxt,nxtcol});
                        pq.push({nxt,nxtcol});
                    }
                }
            }
        }
        return dist;
        
    }
};