//Problem Link:- https://leetcode.com/problems/combination-sum-iv/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        long dp[target + 1];
        dp[0] = 1;
        for (int i = 1, tmp; i <= target; i++) {
            dp[i] = 0;
            
            for (int n: nums) {
                if (i >= n) {
                    tmp = dp[i - n];
                    if (tmp == -1) {
                        dp[i] = -1;
                        break;
                    }
                    dp[i] += dp[i - n];
                }
                if (dp[i] > INT_MAX) {
                    dp[i] = -1;
                    break;
                }
            }
        }
        return dp[target];
    }
};