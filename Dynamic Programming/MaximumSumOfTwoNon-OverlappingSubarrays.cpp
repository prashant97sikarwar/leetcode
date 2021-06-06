//Problem Link:- https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums, int x,int y){
        int n = nums.size();
        vector<int> left(n,0), right(n,0);
        int sm = 0;
        for(int i=0;i<n;i++){
            if (i < x){
                sm += nums[i];
                left[i] = sm;
            }
            else{
                sm = sm + nums[i]-nums[i-x];
                left[i] = max(sm,left[i-1]);
            }
        }
        sm = 0;
        for(int i=n-1;i>=0;i--){
            if (i+y >= n){
                sm += nums[i];
                right[i] = sm;
            }
            else{
                sm = sm + nums[i] - nums[i+y];
                right[i] = max(sm,right[i+1]);
            }
        }
        int res = 0;
        for(int i=x-1;i<n-y;i++){
            res = max(res,left[i] + right[i+1]);
        }
        return res;
        
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int x, int y) {
        return max(helper(nums,x,y), helper(nums,y,x));
    }
};