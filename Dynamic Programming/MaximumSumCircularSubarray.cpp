//Problem Link:- https://leetcode.com/problems/maximum-sum-circular-subarray/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int curMax = nums[0];
        int globalMax = nums[0];
        
        for(int i=1;i<n;i++){
            curMax = max(curMax + nums[i],nums[i]);
            globalMax = max(globalMax,curMax);
        }
        int curMin = nums[0];
        int globalMin = nums[0];
        
        for(int i=1;i<n;i++){
            curMin = min(curMin + nums[i],nums[i]);
            globalMin = min(curMin,globalMin);
        }
        if (globalMin == totalSum){
            return globalMax;
        }
        int result = max(globalMax, totalSum - globalMin);
        return result;
    }
};