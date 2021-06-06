//Problem Link:- https://leetcode.com/problems/constrained-subsequence-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> dp(n,0);
        dp[0] = nums[0];
        pq.push({nums[0],0});
        for(int i=1;i<n;i++){
            while (!pq.empty() && i - pq.top().second > k){
                pq.pop();
            }
            int mx = max(0,pq.top().first);
            dp[i] = nums[i] + mx;
            pq.push({dp[i],i});
        }
        int res = INT_MIN;
        for(int i=0;i<n;i++){
            res = max(res,dp[i]);
        }
        return res;
    }
};