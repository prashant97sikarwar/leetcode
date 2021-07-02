//Problem Link:- https://leetcode.com/problems/maximum-product-difference-between-two-pairs/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int f = nums[0]*nums[1];
        int s = nums[n-1]*nums[n-2];
        return s-f;
    }
};

