//Problem Link:- https://leetcode.com/problems/maximum-earnings-from-taxi/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
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
    
    long long maxTaxiEarnings(int m, vector<vector<int>>& rides) {
        for(auto &x : rides){
            int val = x[1] - x[0];
            x[2] += val;
        }
        sort(rides.begin(),rides.end(),cmp);
        const int n = rides.size();
        vector<long long> dp(n,0);
        dp[0] = rides[0][2];
        for(int i=1;i<n;i++){
            long long prof = (1LL)*rides[i][2];
            int l = findValid(rides,i);
            if (l != -1){
                prof += dp[l];
            }
            dp[i] = max(prof, dp[i-1]);
        }
        return dp[n-1];
    }
};