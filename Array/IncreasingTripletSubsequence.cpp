//Problem Link:- https://leetcode.com/problems/increasing-triplet-subsequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int f = INT_MAX, s = INT_MAX, t = INT_MAX;
        for(int i=0;i<n;i++){
            if (f >= nums[i]){
                f = nums[i];
            }
            else if (s >= nums[i]){
                s = nums[i];
            }
            else{
                t = nums[i];
                return true;
            }
        }
        return false;
    }
};