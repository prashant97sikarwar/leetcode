//problem Link:- https://leetcode.com/problems/single-number-iii/

/* Given an integer array nums, in which exactly two elements appear only once and all the 
other elements appear exactly twice. Find the two elements that appear only once. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xxr = 0;
        for(int i=0;i<nums.size();i++){
            xxr ^= nums[i];
        }
        xxr = xxr & (~xxr + 1);
        int a = 0,b = 0;
        for(int i=0;i<nums.size();i++){
            if (nums[i] & xxr)
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        return {a,b};
    }
};