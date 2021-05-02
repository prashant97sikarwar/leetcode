//Problem Link:- https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>&nums,int dv){
        int sm = 0;
        for(int i=0;i<nums.size();i++){
            sm += ((nums[i]-1) / dv +1);
        }
        return sm;
        
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int res = INT_MAX;
        while (l <= r){
            int mid = l + (r-l)/2;
            int val = helper(nums,mid);
            if (val <= threshold){
                res = min(res,mid);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return res;
    }
};