//Problem Link:- https://leetcode.com/problems/permutations-ii/

/* Given a collection of numbers, nums, that might contain duplicates, return all possible 
unique permutations in any order. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> ans;
    
    void permute(vector<int> &nums,int index){
        if (index >= nums.size()){
            if (s.find(nums) == s.end()){
                ans.push_back(nums);
                s.insert(nums);
            }
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            permute(nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permute(nums,0);
        return ans;
        
    }
};