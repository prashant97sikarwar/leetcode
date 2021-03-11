//Problem Link:- https://leetcode.com/problems/subsets-ii/

/* Given an integer array nums that may contain duplicates, return all possible subsets (the 
power set).*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<vector<int>> s;
    void helper(vector<vector<int>>& result,vector<int>& path,vector<int>nums, int index){
        if (index >= nums.size() && s.find(path) == s.end()){
            result.push_back(path);
            s.insert(path);
            return;
        }
        if (index >= nums.size())
            return;
        path.push_back(nums[index]);
        helper(result,path,nums,index+1);
        path.pop_back();
        helper(result,path,nums,index+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        if (nums.size() == 0)
            return result;
        vector<int> path;
        helper(result,path,nums,0);
        return result;
    }
};