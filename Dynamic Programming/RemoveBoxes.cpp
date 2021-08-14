//Problem Link:- https://leetcode.com/problems/remove-boxes/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][101][101];
    int helper(vector<int>&boxes,int i,int j,int k){
        if (i > j){
            return 0;
        }
        if (dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        
        int res = INT_MIN;
        res = (k+1)*(k+1) + helper(boxes,i+1,j,0);
        
        for(int g=i+1;g<=j;g++){
            if (boxes[i] == boxes[g]){
                res = max(res,helper(boxes,i+1,g-1,0) + helper(boxes,g,j,k+1));
            }
        }
        return dp[i][j][k] = res;
    }
    
    int removeBoxes(vector<int>& boxes) {
        const int n = boxes.size();
        memset(dp,-1,sizeof(dp));
        return helper(boxes,0,n-1,0);
        
    }
};