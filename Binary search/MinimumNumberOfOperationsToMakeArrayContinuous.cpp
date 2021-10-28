//Problem Link:- https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ans = 0; 
        sort(nums.begin(), nums.end()); 
        nums.erase(unique(nums.begin(), nums.end()), nums.end()); // remove duplicates
        
        for (int i = 0, ii = 0; i < nums.size(); ++i) {
            if (nums[i] - nums[ii] >= n) ++ii; 
            ans = max(ans, i - ii + 1); 
        }
        return n - ans; 
    }
};