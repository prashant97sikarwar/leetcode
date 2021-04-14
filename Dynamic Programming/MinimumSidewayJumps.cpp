//Problem Link:- https://leetcode.com/problems/minimum-sideway-jumps/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[500005][4];
    int helper(int st,int end,vector<int> &nums,int pos){
        if (st == end){
            return 0;
        }
        if (dp[st][pos] != -1){
            return dp[st][pos];
        }
        else if (nums[st+1] == pos){
            int first = INT_MAX;
            for(int k=1;k<=3;k++){
                if (k == pos || nums[st] == k){
                    continue;
                }
                else{
                    first = min(first,1 + helper(st,end,nums,k));
                }
            }
            return dp[st][pos] = first;
        }
        else{
            return dp[st][pos] = helper(st+1,end,nums,pos);
        }
        
    }
    int minSideJumps(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return helper(0,n,nums,2);
    }
};