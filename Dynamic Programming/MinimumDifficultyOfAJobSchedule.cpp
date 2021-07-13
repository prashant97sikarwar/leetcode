//Problem Link:- https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        int dp[305][12];
public:
    int helper(vector<int>&nums,int d,int idx){
        if (d == 1){
            int mx = -1;
            for(int i=idx;i<nums.size();i++){
                mx = max(mx,nums[i]);
            }
            return mx;
        }
        if (dp[idx][d] != -1){
            return dp[idx][d];
        }
        int mx = -1;
        int res = INT_MAX;
        for(int i=idx;i<nums.size()-d+1;i++){
            mx = max(mx,nums[i]);
            res = min(res,mx + helper(nums,d-1,i+1));
        }
        return dp[idx][d] = res;
    }
    
    int minDifficulty(vector<int>& nums, int d) {
        if (nums.size() < d){
            return -1;
        }
        memset(dp,-1,sizeof(dp));
        return helper(nums,d,0);
    }
};