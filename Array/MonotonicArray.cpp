//Problem Link:- https://leetcode.com/problems/monotonic-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper1(vector<int>&nums){
        for(int i=1;i<nums.size();i++){
            if (nums[i] < nums[i-1]){
                return false;
            }
        }
        return true;
    }
    
    bool helper2(vector<int>&nums){
        for(int i=1;i<nums.size();i++){
            if (nums[i] > nums[i-1]){
                return false;
            }
        }
        return true;
    }
    
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() <= 2){
            return true;
        }
        bool incr = false,decr = false;
        incr = helper1(nums);
        decr = helper2(nums);
        return incr || decr;
    }
};