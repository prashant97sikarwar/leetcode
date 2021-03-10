//Problem Link:- https://leetcode.com/problems/permutations/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    
    void permute(vector<int>& nums, int index){
        if (index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            permute(nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
        
    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums,0);
        return ans;
    }
};