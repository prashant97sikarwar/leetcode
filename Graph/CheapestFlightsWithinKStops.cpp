//Problem Link:- https://leetcode.com/problems/cheapest-flights-within-k-stops/

/*There are n cities connected by m flights. Each flight starts from city u and arrives at v 
with a price w.Now given all the cities and flights, together with starting city src and the 
destination dst, your task is to find the cheapest price from src to dst with up to k stops. 
If there is no such route, output -1. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int,vector<pair<int,int>>> graph;
        for(auto curr : flights){
            graph[curr[0]].push_back({curr[1],curr[2]});
        }
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,src,K});
        while(!pq.empty()){
            auto detail = pq.top();
            pq.pop();
            int cost = detail[0];
            int node = detail[1];
            int leftstop = detail[2];
            if (node == dst)
                return cost;
            if (leftstop >= 0){
                for(auto x : graph[node]){
                    int v = x.first;
                    pq.push({cost + x.second,v,leftstop-1});
                }
            }
        }
        return -1;
    }
};