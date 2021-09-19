//Problem link:- https://leetcode.com/problems/bus-routes/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        const int n = routes.size();
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<n;i++){
            for(int &stop : routes[i]){
                graph[stop].push_back(i);
            }
        }
        int steps = 0;
        queue<int> pq;
        pq.push(source);
        unordered_set<int> visited;
        visited.insert(source);
        while (!pq.empty()){
            int sz = pq.size();
            while (sz--){
                int node = pq.front();
                pq.pop();
                if (node == target){
                    return steps;
                }
                for(auto bus : graph[node]){
                    for(int stop : routes[bus]){
                        if (visited.find(stop) == visited.end()){
                            visited.insert(stop);
                            pq.push(stop);
                        }
                    }
                    routes[bus].clear(); 
                }
            }
            ++steps;
        }
        return -1;
    }
};