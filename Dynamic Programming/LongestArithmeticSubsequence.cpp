//Problem Link:- https://leetcode.com/problems/longest-arithmetic-subsequence/

/*Given an array A of integers, return the length of the longest arithmetic subsequence in A.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1001, -1));
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[j] - nums[i] + 500;
                if (dp[j][diff] == -1){
                    dp[i][diff] = max(dp[i][diff],2);
                }
                else{
                    dp[i][diff] = max(1+dp[j][diff],dp[i][diff]);
                }
                res = max(res,dp[i][diff]);
            }
        }
        return res;
    }
};