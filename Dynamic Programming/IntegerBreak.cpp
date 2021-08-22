//Problem Link:- https://leetcode.com/problems/integer-break/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int dp[60];
public:
    int helper(int n){
        if (n == 1 || n == 0){
            return 1;
        }
        if (n < 0){
            return 0;
        }
        if (dp[n] != -1){
            return dp[n];
        }
        int res = 0;
        for(int i=1;i<=n;i++){
            res = max(res,i*helper(n-i));
        }
        return dp[n] = res;
    }
    
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        int res = 0;
        for(int i=1;i<n;i++){
            res = max(res, i*helper(n-i));
        }
        return res;
    }
};