//Problem Link:- https://leetcode.com/problems/find-center-of-star-graph/

/* There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph 
is a graph where there is one center node and exactly n - 1 edges that connect the center 
node with every other node.You are given a 2D integer array edges where each edges[i] = 
[ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center 
of the given star graph. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<int> arr(n+1,0);
        for(int i=0;i<n-1;i++){
            arr[edges[i][0]]++;
            arr[edges[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if (arr[i] == n-1)
                return i;
        }
        return 0;
    }
};