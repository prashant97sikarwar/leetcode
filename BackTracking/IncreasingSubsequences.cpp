//Problem Link:- https://leetcode.com/problems/increasing-subsequences/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<vector<int>> ans;
    
    void helper(int idx,int prev,vector<int>&temp,int n,vector<int>&nums){
        if (idx >= n){
            if (temp.size() > 1){
                ans.insert(temp);
            }
            return;
        }
        if (temp.size() > 1){
            ans.insert(temp);
        }
        if (nums[idx] >= nums[prev]){
            temp.push_back(nums[idx]);
            helper(idx+1,idx,temp,n,nums);
            temp.pop_back();
        }
        helper(idx+1,prev,temp,n,nums);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        const int n = nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
            helper(i+1,i,temp,n,nums);
            temp.pop_back();
        }
        vector<vector<int>> result(ans.begin(),ans.end());
        return result;
    }
};