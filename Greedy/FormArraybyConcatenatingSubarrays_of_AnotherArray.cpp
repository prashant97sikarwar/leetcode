//Problem Link:- https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/

/*You are given a 2D integer array groups of length n. You are also given an integer array nums.
you are asked if you can choose n disjoint subarrays from the array nums such that the ith subarray
is equal to groups[i] (0-indexed), and if i > 0, the (i-1)th subarray appears before the ith 
subarray in nums (i.e. the subarrays must be in the same order as groups).Return true if you can do
this task, and false otherwise.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = groups.size();
        int m = nums.size();
        int i=0,j=0;
        while (i < n && j < m){
            int check = j,s = 0;
            for(;s < groups[i].size() && check < m;++check,++s){
                if (groups[i][s] != nums[check])
                    break;
            }   
            if (s == groups[i].size()){
                j = check;
                ++i;
            }
            else
                ++j;
        }   
        return i == groups.size();
    }
};