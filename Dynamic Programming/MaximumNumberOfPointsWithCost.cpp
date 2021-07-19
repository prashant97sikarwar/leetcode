//Problem Link:- https://leetcode.com/problems/maximum-number-of-points-with-cost/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<vector<long long>> dp(n,vector<long long> (m,-1));
        for(int i=0;i<m;i++){
            dp[0][i] = points[0][i];
        }
        for(int i=1;i<n;i++){
            vector<long long> left(m,-1), right(m,-1);
            left[0] = dp[i-1][0], right.back() = dp[i-1].back() - points[i].size() + 1;;
            for(int k=1;k<m;k++){
                left[k] = max(left[k-1],dp[i-1][k] + k);
            }
            for(int k=m-2;k>=0;k--){
                right[k] = max(right[k+1],dp[i-1][k] - k);
            }
            for(int j=0;j<m;j++){
                dp[i][j] = max(left[j]-j, right[j]+j) + points[i][j];
            }
        }
        long long res = 0;
        for(int i=0;i<m;i++){
            res = max(res,dp[n-1][i]);
        }
        return res;
    }
};