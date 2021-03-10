//Problem Link:- https://leetcode.com/problems/generate-parentheses/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<string> &ans, int left, int right, int n, string curr){
        if (curr.length() >= 2 * n){
            ans.push_back(curr);
            return;
        }
        if (left < n){
            helper(ans,left+1,right,n,curr+'(');
        }
        if (right < left)
            helper(ans,left,right+1,n,curr+')');
    
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans,0,0, n, "");
        return ans;
    }
};