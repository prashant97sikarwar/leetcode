//Problem Link:- https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

#include<bits/stdc++.h>
using namespace std;

class TreeAncestor {
    private:
    vector<vector<int>> dp;
    int h;
public:
    TreeAncestor(int n, vector<int>& parent) {
        dp.resize(n+1,vector<int> (20,-1));
        for(int i=0;i<n;i++){
            dp[i][0] = parent[i];
        }
        for(int i=1;i<20;i++){
            for(int v=1;v<n;v++){
                if (dp[v][i-1] != -1){
                    dp[v][i] = dp[dp[v][i-1]][i-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<20;i++){
            if (k & (1 << i)){
                node = dp[node][i];
                if (node == -1){
                    return -1;
                }
            }
        }
        return node;
    }
};