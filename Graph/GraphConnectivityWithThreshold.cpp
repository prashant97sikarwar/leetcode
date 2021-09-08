//Problem Link;- https://leetcode.com/problems/graph-connectivity-with-threshold/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int parent[10005];
    int rank[10005];
public:
    int find(int u){
        if (u == parent[u]){
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v){
        int x = find(u);
        int y = find(v);
        
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
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<bool> result;
        
        for(int i=0;i<=n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(int i=threshold+1;i<=n;i++){
            for(int j=2;i*j<=n;j++){
                merge(i,i*j);
            }
        }
        
        for(auto x : queries){
            int u = x[0];
            int v = x[1];
            
            if (find(u) == find(v)){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
        return result;
    }
};