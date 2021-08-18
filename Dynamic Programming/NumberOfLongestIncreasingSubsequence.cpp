//Problem Link:- https://leetcode.com/problems/number-of-longest-increasing-subsequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<pair<int,int>> dp(n);
        for(int i=0;i<n;i++){
            dp[i].first = 1;
            dp[i].second = 1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if (nums[j] < nums[i]){
                    if (dp[i].first < 1 + dp[j].first){
                        dp[i].first = 1 + dp[j].first;
                        dp[i].second = dp[j].second;   
                    }
                    else  if (dp[i].first == 1 + dp[j].first){
                        dp[i].second += dp[j].second;
                    }
                }
            }
        }
        int maxLength = 1;
        for(int i=0;i<n;i++){
            maxLength = max(maxLength, dp[i].first);
        }
        int result = 0;
        for(int i=0;i<n;i++){
            if (dp[i].first == maxLength){
                result += dp[i].second;
            }
        }
        return result;
    }
};