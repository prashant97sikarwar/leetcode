//Problem Link:- https://leetcode.com/problems/maximum-subarray-min-product/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long long res =  0;
        long long MOD = 1e9+7;
        nums.push_back(0);
        stack<long long> st;
        vector<long long> dp(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            dp[i+1] = nums[i] + dp[i];
        }
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                int j = st.top();
                st.pop();
                res = max(res,1LL*nums[j]*(dp[i] - dp[st.empty() ? 0 : st.top()+1]));
            }
            st.push(i);
        }
        return res%MOD;
    }
};