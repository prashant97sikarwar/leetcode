//Problem Link:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[5001][2];
    int helper(int i,vector<int>& nums, int own){
        if (i >= nums.size()){
            return 0;
        }
        if (dp[i][own] != -1){
            return dp[i][own];
        }
        if (own){
            int op1 = nums[i] + helper(i+2,nums,0);
            int op2 = helper(i+1,nums,1);
            return dp[i][own] = max(op1,op2);
        }
        else{
            int op1 = -nums[i] + helper(i+1,nums,1);
            int op2 = helper(i+1,nums,0);
            return dp[i][own] = max(op1,op2);
        }
    }
    
    int maxProfit(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(0,nums,0); 
    }
};