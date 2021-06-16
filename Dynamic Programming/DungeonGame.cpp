//Problem Link:- https://leetcode.com/problems/dungeon-game/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<int>> dp(n,vector<int> (m,INT_MAX));
        dp[n-1][m-1] = max(1-nums[n-1][m-1], 1);
        for(int i=n-2;i>=0;i--){
            dp[i][m-1] = max(dp[i+1][m-1] - nums[i][m-1], 1);
        }
        for(int i=m-2;i>=0;i--){
            dp[n-1][i] = max(dp[n-1][i+1] - nums[n-1][i],1);
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j] = max(min(dp[i+1][j], dp[i][j+1]) - nums[i][j],1);
            }
        }
        return dp[0][0];
    }
};