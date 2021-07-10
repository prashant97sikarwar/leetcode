//problem Link:- https://leetcode.com/problems/maximum-alternating-subsequence-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        long long dp[100005][2];
public:
    long long helper(int i,int own,vector<int>&nums){
        if (i >= nums.size()){
            return 0;
        }
        if (dp[i][own] != -1){
            return dp[i][own];
        }
        if (own){
            long long op1 = helper(i+1,own,nums);
            long long op2 = -nums[i] + helper(i+1,0,nums);
            return dp[i][own] = max(op1,op2);
        }
        else{
            long long op1 = helper(i+1,own,nums);
            long long op2 = nums[i] + helper(i+1,1,nums);
            return dp[i][own] = max(op1,op2);
        }
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,nums);
    }
};