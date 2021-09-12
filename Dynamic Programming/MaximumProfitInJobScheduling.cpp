//Problem Link:- https://leetcode.com/problems/maximum-profit-in-job-scheduling/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int dp[50005];
public:
    static bool cmp(vector<int>&a, vector<int>& b){
        if (a[1] == b[1]){
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    
    int findValid(vector<vector<int>>& nums, int idx){
        int low = 0, high = idx-1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid][1] <= nums[idx][0]){
                if (nums[mid+1][1] <= nums[idx][0]){
                    low = mid +1;
                }
                else{
                    return mid;
                }
            }
            else{
                high = mid -1;
            }
        }
        return -1;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> nums;
        const int n = startTime.size();
        
        for(int i=0;i<n;i++){
            vector<int> temp = {startTime[i], endTime[i], profit[i]};
            nums.push_back(temp);
        }
        
        sort(nums.begin(),nums.end(),cmp);
        dp[0] = nums[0][2];
        for(int i=1;i<n;i++){
            int prof = nums[i][2];
            int l = findValid(nums,i);
            if (l != -1){
                prof += dp[l];
            }
            dp[i] = max(prof, dp[i-1]);
        }
        return dp[n-1];
    }
};