//Problem Link:- https://leetcode.com/problems/burst-balloons/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int dp[502][502];
public:
    int helper(int s,int e,vector<int>&nums){
        if (s == e-1){
            return 0;
        }
        if (dp[s][e] != -1){
            return dp[s][e];
        }
        int res = INT_MIN;
        for(int k=s+1;k<=e-1;k++){
            res = max(res,nums[s]*nums[k]*nums[e] + helper(s,k,nums) + helper(k,e,nums));
        }
        return dp[s][e] = res;
    }
    
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return helper(0,nums.size()-1,nums);
    }
};