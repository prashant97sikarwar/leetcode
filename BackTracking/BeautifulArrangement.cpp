//Problem Link:- https://leetcode.com/problems/beautiful-arrangement/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int n,int i,vector<bool>&visited,int &res){
        if (i > n){
            res++;
        }
        for(int idx=1;idx<=n;idx++){
            if (!visited[idx] && (i%idx == 0 || idx%i == 0)){
                visited[idx] = true;
                helper(n,i+1,visited,res);
                visited[idx] = false;
            }
        }
    }
    
    int countArrangement(int n) {
        if (n == 1){
            return 1;
        }
        int res = 0;
        vector<bool> visited(n+1,false);
        helper(n,1,visited,res);
        return res;
    }
};