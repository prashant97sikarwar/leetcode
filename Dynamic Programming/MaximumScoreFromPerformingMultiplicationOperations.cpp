//Problem link:- https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

/* You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m.
The arrays are 1-indexed.You begin with a score of 0. You want to perform exactly m operations. On 
the ith operation (1-indexed), you will:
1.Choose one integer x from either the start or the end of the array nums.
2.Add multipliers[i] * x to your score.
3.Remove x from the array nums.
Return the maximum score after performing m operations. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1000][1000];
    
    int helper(vector<int>& nums, vector<int>& arr,int left, int right,int index){
        if (index >= arr.size())
            return 0;
        if (dp[left][index] != -1)
            return dp[left][index];
        
        int s1 = nums[left] * arr[index] + helper(nums,arr,left+1,right,index+1);
        int s2 = nums[right] * arr[index] + helper(nums,arr,left,right-1,index+1);
        return dp[left][index] = max(s1,s2);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        return helper(nums,arr,0,nums.size()-1,0);
    }
};