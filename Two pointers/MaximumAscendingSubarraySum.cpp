//Problem Link:- https://leetcode.com/problems/maximum-ascending-subarray-sum/

/* Given an array of positive integers nums, return the maximum possible sum of an ascending 
subarray in nums. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = nums[0];
        int ans = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            if (nums[i] > nums[i-1]){
                ans += nums[i];
            }
            else{
                res = max(res,ans);
                ans = nums[i];
            }
        }
        res = max(res,ans);
        return res;
    }
};