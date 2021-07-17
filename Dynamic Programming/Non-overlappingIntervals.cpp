//Problem Link:- https://leetcode.com/problems/non-overlapping-intervals/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), res = 0,sz = 0;
        sort(intervals.begin(),intervals.end());
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if (intervals[j][1] <= intervals[i][0] && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                }
            }
        }
        for(int i=0;i<n;i++){
            res = max(res,dp[i]);
        }
        return n - res;
    }
};