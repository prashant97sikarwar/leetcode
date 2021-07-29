//Problem Link:- https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int u,vector<int>& parent){
        if (parent[u] == u){
            return u;
        }
        return parent[u] = find(parent[u],parent);
    }
    
    void merge(int u,int v,vector<int>& parent,vector<int>& rank){
        int x = find(u,parent);
        int y = find(v,parent);
        if (x == y){
            return;
        }
        if (rank[x] > rank[y]){
            parent[y] = x;
            rank[x] += rank[y];
        }
        else{
            parent[x] = y;
            rank[y] += rank[x]; 
        }
    }
    
    int MST(int n,vector<vector<int>>& edges,vector<int>& include,vector<int>& exclude){
        vector<int> parent(n,0);
        vector<int> rank(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        int cost = 0;
        if (include.size() != 0){
            if (find(include[0],parent) != find(include[1],parent)){
                merge(include[0],include[1],parent,rank);
                cost += include[2];   
            }
        }
        for(auto x : edges){
            if (x != exclude){
                int u = x[0];
                int v = x[1];
                int w = x[2];
                if (find(u,parent) != find(v,parent)){
                    merge(u,v,parent,rank);
                    cost += w;
                }   
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if (parent[i] == i){
                cnt++;
                if (cnt > 1){
                    return 1e5;
                }
            }
        }
        return cost;
    }
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[2] < b[2];
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        map<vector<int>,int> idxList;
        const int sz = edges.size();
        for(int i=0;i<sz;i++){
            idxList[edges[i]] = i;
        }
        sort(edges.begin(),edges.end(),cmp);
        vector<vector<int>> result;
        vector<int> critical,pseudo;
        vector<int> include,exclude;
        int cost = MST(n,edges,include,exclude);
        for(vector<int>& x : edges){
            int excost = MST(n,edges,include,x);
            if (excost > cost){
                critical.push_back(idxList[x]);
            }
            else{
                int incost = MST(n,edges,x,exclude);
                if (incost == cost){
                    pseudo.push_back(idxList[x]);
                }
            }
        }
        result.push_back(critical);
        result.push_back(pseudo);
        return result;
    }
};