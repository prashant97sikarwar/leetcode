//Problem Link:- https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

/* Given a tree (i.e. a connected, undirected graph that has no cycles) consisting of n nodes 
numbered from 0 to n - 1 and exactly n - 1 edges. The root of the tree is the node 0, and each 
node of the tree has a label which is a lower-case character given in the string labels (i.e. 
The node with the number i has the label labels[i]).The edges array is given on the form 
edges[i] = [ai, bi], which means there is an edge between nodes ai and bi in the tree.
Return an array of size n where ans[i] is the number of nodes in the subtree of the ith node 
which have the same label as node i. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> helper(unordered_map<int,vector<int>>& graph,string& labels,vector<int>&result,int node, vector<bool>& visited){
        visited[node] = true;
        vector<int> freq(26,0);
        char ch = labels[node];
        vector<int> subtree;
        for(auto x : graph[node]){
            if (!visited[x]){
                subtree = helper(graph,labels,result,x,visited);
                for(int j=0;j<26;j++){
                    freq[j] += subtree[j];
                }
            }
        }
        freq[ch-'a']++;
        visited[node] = false;
        result[node] = freq[ch-'a'];
        return freq;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>> graph;
        for(auto x : edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> result(n,0);
        vector<bool> visited(n,false);
        helper(graph,labels,result,0,visited);
        return result;
           
    }
};