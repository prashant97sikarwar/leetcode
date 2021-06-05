//Problem Link:- https://leetcode.com/problems/paint-house/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[100001][3];
    int helper(int i,int ch,vector<vector<int>>& costs){
        if (i >= costs.size()){
            return 0;
        }
        if (dp[i][ch] != -1){
            return dp[i][ch];
        }
        if (ch == 0){
            int op1 = costs[i][0] + helper(i+1,1,costs);
            int op2 = costs[i][0] + helper(i+1,2,costs);
            return dp[i][ch] = min(op1,op2);
        }
        else if (ch == 1){
            int op1 = costs[i][1] + helper(i+1,0,costs);
            int op2 = costs[i][1] + helper(i+1,2,costs);
            return dp[i][ch] = min(op1,op2);
        }
        else{
            int op1 = costs[i][2] + helper(i+1,0,costs);
            int op2 = costs[i][2] + helper(i+1,1,costs);
            return dp[i][ch] = min(op1,op2);
        }

    }

    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return min(costs[0][0], min(costs[0][1], costs[0][2]));
        }
        memset(dp,-1,sizeof(dp));
        int op1 = helper(0,0,costs);
        int op2 = helper(0,1,costs);
        int op3 = helper(0,2,costs);
        return min(op1,min(op2,op3));
    }
};