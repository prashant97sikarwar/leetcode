//Problem Link:- https://leetcode.com/problems/combination-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void helper(vector<int> candidates, int target,vector<vector<int>>& result,vector<int>path,int index, int sm){
        if (sm == target){
            result.push_back(path);
            return;
        }
        if (sm > target)
            return;
        if (index >= candidates.size())
            return;
        helper(candidates,target,result,path,index+1,sm);
        path.push_back(candidates[index]);
        helper(candidates,target,result,path,index,sm+candidates[index]);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.size() == 0)
            return result;
        vector<int> path;
        helper(candidates,target,result,path,0,0);
        return result;
        
    }
};