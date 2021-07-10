//Problem Link:- https://leetcode.com/problems/delete-and-earn/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> arr(10004,0);
        vector<int> dp(10004,0);
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        if (nums.size() == 0){
            return 0;
        }
        if (nums.size() == 1){
            return nums[0];
        }
        int mx = 0;
        dp[1] = arr[1];
        for(int i=2;i<10004;i++){
            if (arr[i] > 0){
                dp[i] = max(dp[i-1],arr[i]*i + dp[i-2]);
            }
            else{
                dp[i] = dp[i-1];
            }
            mx = max(dp[i],mx);
        }
        return mx;
    }
};