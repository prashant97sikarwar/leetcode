//Problem link:- https://leetcode.com/problems/combinations/

/* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& result,vector<int> & path,int num,int n, int k){
        if (path.size() == k){
            result.push_back(path);
            return;
        }
        if (num > n)
            return;
        path.push_back(num);
        helper(result,path,num+1,n,k);
        path.pop_back();
        helper(result,path,num+1,n,k);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        helper(result,path,1,n,k);
        return result;
    }
};