//Problem link:- https://leetcode.com/problems/combination-sum-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int>& candidates,int target,int index,int sm,vector<int>path, vector<vector<int>>& result){
        if (sm == target){
            result.push_back(path);
            return;
        }
        if (sm > target)
            return;
        for(int i=index;i<candidates.size();i++){
            if (i == index || candidates[i] != candidates[i-1]){
                path.push_back(candidates[i]);
                helper(candidates,target,i+1,sm+candidates[i],path,result);
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.size() == 0)
            return result;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,0,0,path,result);
        return result;
    }
};