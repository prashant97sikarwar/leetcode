//Problem Link:- https://leetcode.com/problems/build-array-from-permutation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res (sz);
        for(int i=0;i<sz;i++){
            res[i] = nums[nums[i]];
        }
        return res;
    }
};