//Problem Link:- https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

/* There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] 
represents a bidirectional and weighted edge between cities fromi and toi, and given the 
integer distanceThreshold.Return the city with the smallest number of cities that are 
reachable through some path and whose distance is at most distanceThreshold, If there are 
multiple such cities, return the city with the greatest number. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> arr[104];
    int dist[104];
    int helper(int src,int mn){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        for(int i=0;i<104;i++){
            dist[i] = INT_MAX;
        }
        dist[src] = 0;
        while (!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto curr : arr[node]){
                if (dist[curr.first] > d + curr.second){
                    dist[curr.first] = d + curr.second;
                    pq.push({dist[curr.first],curr.first});
                }
            }
        }
        int count = 0;
        for(int i=0;i<104;i++){
            if (dist[i] <= mn)
                count++;
        }
        return count;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int mn) {
        for(int i=0;i<edges.size();i++){
            arr[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            arr[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int ans = INT_MAX;
        int res = -1;
        for(int i=0;i<n;i++){
            int num = helper(i,mn);
            if (num <= ans){
                ans = num;
                res = i;
            }
        }
        return res;
    }
};