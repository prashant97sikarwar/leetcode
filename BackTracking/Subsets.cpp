//Problem Link:- https://leetcode.com/problems/subsets/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& result,vector<int>& path,vector<int>nums, int index){
        if (index >= nums.size()){
            result.push_back(path);
            return;
        }
        path.push_back(nums[index]);
        helper(result,path,nums,index+1);
        path.pop_back();
        helper(result,path,nums,index+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0)
            return result;
        vector<int> path;
        helper(result,path,nums,0);
        return result;
    }
};