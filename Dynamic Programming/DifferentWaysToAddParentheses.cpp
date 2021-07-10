//Problem Link:- https://leetcode.com/problems/different-ways-to-add-parentheses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    map<pair<int,int>, vector<int>> dp;
public:
    int compute(int a,char op,int b){
        if (op == '+'){
            return a + b;
        }
        else if (op == '-'){
            return a - b;
        }
        else {
            return a * b;
        }
    }
    
    bool isOperator(char x){
        if (x == '+' || x == '-' || x == '*'){
            return true;
        }
        return false;
    }
    vector<int> helper(int st,int end,string s){
        if (st >= end){
            return {};
        }
        pair<int,int> pd = {st,end};
        if (dp.find(pd) != dp.end()){
            return dp[pd];
        }
        vector<int> ans;
        int flag = false;
        for(int i=st;i<end;i++){
            if (isOperator(s[i])){
                flag = true;
                vector<int> left = helper(st,i,s);
                vector<int> right = helper(i+1,end,s);
                for(auto x : left){
                    for(auto y : right){
                        int res = compute(x,s[i],y);
                        ans.push_back(res);
                    }
                }
            }
        }
        if (flag == false){
            ans.push_back(stoi(s.substr(st,end-st)));
        }
        return dp[pd] = ans;
    }
    
    vector<int> diffWaysToCompute(string s) {
        dp.clear();
        return helper(0,s.length(),s);
    }
};