//Problem Link:- https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHeight(vector<vector<int>>& nums) {
        int n = nums.size();
        for(auto &x : nums){
            sort(x.begin(),x.end());
        }
        sort(nums.begin(),nums.end());
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            dp[i] = nums[i][2];
            for(int j=0;j<i;j++){
                if (nums[j][0] <= nums[i][0] && nums[j][1] <= nums[i][1] && nums[j][2] <= nums[i][2]){
                    dp[i] = max(dp[i],dp[j] + nums[i][2]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};