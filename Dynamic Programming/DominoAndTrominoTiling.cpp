//Problem Link:- https://leetcode.com/problems/domino-and-tromino-tiling/

#include<bits/stdc++.h>
using namespace  std;

class Solution {
public:
    const int mod = 1e9 +7; 
    int numTilings(int n) {
        if (n == 1){
            return 1;
        }
        if (n == 2){
            return 2;
        }
        vector<int> dp(n+1,0);
        dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 5;
        for(int i=4;i<=n;i++){
            dp[i] = (2*dp[i-1]%mod + dp[i-3]%mod)%mod;
            dp[i] %= mod;
        }
        return dp[n]%mod;
    }
};