//Problem Link:- https://leetcode.com/problems/distinct-subsequences-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        const int n = s.length();
        const int MOD = 1e9 + 7;
        vector<int> dp(n+1,0), last(26,-1);
        dp[0] = 1;
        for(int i=0;i<n;i++){
            int x = s[i]-'a';
            dp[i+1] = dp[i]*2 % MOD;
            if (last[x] >= 0){
                dp[i+1] -= dp[last[x]];
            }
            dp[i+1] %= MOD;
            last[x] = i;
        }
        dp[n]--;
        if (dp[n] < 0){
            dp[n] += MOD;
        }
        return dp[n];
    }
};