//Problem Link:- https://leetcode.com/problems/maximum-score-of-a-good-subarray/

/* You are given an array of integers nums (0-indexed) and an integer k.The score of a subarray
(i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a 
subarray where i <= k <= j.Return the maximum possible score of a good subarray. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int res = nums[k], mini = nums[k], i = k,j = k;
        int n = nums.size();
        while (i > 0 || j < n-1){
            if ((i > 0 ? nums[i-1]:0) < (j < n ? nums[j+1]:0)){
                mini = min(mini,nums[++j]);
            }
            else{
                mini = min(mini,nums[--i]);
            }
            res = max(res,mini * (j-i+1));
        }
        return res;
    }
};