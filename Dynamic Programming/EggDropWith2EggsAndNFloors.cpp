//Problem Link:- https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>> dp(3,vector<int> (n+1,INT_MAX));
        for(int i=0;i<=n;i++){
            dp[0][i] = 0;
            dp[1][i] = i;
        }
        for(int i=1;i<=2;i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        int eggs = 2;
        for(int floor=2;floor<=n;floor++){
            dp[eggs][floor] = INT_MAX;
            for(int check=1;check<=floor;check++){
                int op1 = dp[eggs-1][check-1];
                int op2 = dp[eggs][floor-check];
                int out = 1 + max(op1,op2);
                dp[eggs][floor] = min(dp[eggs][floor], out);
            }
        }
        return dp[2][n];
    }
};