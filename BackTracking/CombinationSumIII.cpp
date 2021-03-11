//Problem Link:- https://leetcode.com/problems/combination-sum-iii/

/* Find all valid combinations of k numbers that sum up to n such that the following 
conditions are true:Only numbers 1 through 9 are used and Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same 
combination twice, and the combinations may be returned in any order. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arr;
    
    void helper(vector<vector<int>> &result,vector<int>& path, int index,int sm,int n, int k,int cnt){
        if (sm == n && cnt == k){
            result.push_back(path);
            return;
        }
        if (index >= arr.size())
            return;
        path.push_back(arr[index]);
        helper(result,path,index+1,sm+arr[index],n,k,cnt+1);
        path.pop_back();
        helper(result,path,index+1,sm,n,k,cnt);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        for(int i=1;i<10;i++)
            arr.push_back(i);
        helper(result,path,0,0,n,k,0);
        return result;
        
    }
};