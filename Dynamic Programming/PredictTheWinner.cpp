//Problem Link:- https://leetcode.com/problems/predict-the-winner/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        int dp[22][22][2];
public:
    int helper(int turn,int i,int e,vector<int> &arr){
        if (i > e){
            return 0;
        }
        if (dp[i][e][turn] != -1){
            return dp[i][e][turn];
        }
        if (turn == 0){
            int op1 = arr[i] + helper(1,i+1,e,arr);
            int op2 = arr[e] + helper(1,i,e-1,arr);
            return dp[i][e][turn] = max(op1,op2);
        }
        else{
            int op1 = -arr[i] + helper(0,i+1,e,arr);
            int op2 = -arr[e] + helper(0,i,e-1,arr);
            return dp[i][e][turn] = min(op1,op2);
        }
    }
    
    bool PredictTheWinner(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        int n = arr.size();
        int res = helper(0,0,n-1,arr);
        if (res >= 0){
            return true;
        }
        return false;
    }
};