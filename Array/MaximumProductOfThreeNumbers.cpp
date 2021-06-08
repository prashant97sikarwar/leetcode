//Problem Link:- https://leetcode.com/problems/maximum-product-of-three-numbers/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int op1 = nums[0]*nums[1]*nums[n-1];
        int op2 = nums[n-1]*nums[n-2]*nums[n-3];
        return max(op1,op2);
    }
};