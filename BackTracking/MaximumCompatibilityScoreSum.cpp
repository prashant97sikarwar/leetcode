//Problem Link:- https://leetcode.com/problems/maximum-compatibility-score-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int dp[10][10];
    int result;
public:
    void permute(int idx,vector<int> temp,int n){
        if (idx >= n){
            int score = 0;
            for(int i=0;i<temp.size();i++){
                score += dp[i][temp[i]];
            }
            result = max(result,score);
            return;
        }
        for(int i=0;i<temp.size();i++){
            if (temp[i] == -1){
                temp[i] = idx;
                permute(idx+1,temp,n);
                temp[i] = -1;
            }
        }
    }
    
    int helper(vector<int>&nums1,vector<int>&nums2){
        int score = 0;
        for(int i=0;i<nums1.size();i++){
            if (nums1[i] == nums2[i]){
                score++;
            }
        }
        return score;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& s, vector<vector<int>>& m) {
        const int n = s.size();
        result = 0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<m.size();j++){
                int score = helper(s[i],m[j]);
                dp[i][j] = score;
            }
        }
        vector<int> temp(n,-1);
        permute(0,temp,n);
        return result;
    }
};