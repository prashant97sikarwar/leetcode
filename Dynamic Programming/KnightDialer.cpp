//Problem Link:- https://leetcode.com/problems/knight-dialer/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    const int mod = 1e9 + 7;
    vector<vector<int>> mobile = {{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
public:
    int knightDialer(int n) {
        vector<vector<int>> dp(n+1,vector<int> (10,0));
        int res = 0;
        for(int i=0;i<=9;i++){
            dp[1][i] = 1;
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<=9;j++){
                for(int x : mobile[j]){
                    dp[i][j] = (dp[i][j]%mod + dp[i-1][x]%mod)%mod;
                }
            }
        }
        for(int j=0;j<=9;j++){
            res += dp[n][j]%mod;
            res %= mod;
        }
        return res;
    }
};