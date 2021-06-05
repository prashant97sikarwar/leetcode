//Problem Link:- https://leetcode.com/problems/last-stone-weight-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        if (n == 1){
            return stones[0];
        }
        int sm = accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>> dp(n+1,vector<int> (sm/2+1));
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=sm/2;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sm/2;j++){
                if (stones[i-1] <= j){
                    dp[i][j] = dp[i-1][j-stones[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int i = sm/2;
        for(; i>=0; i--) {
            if(dp[n][i] == true)
                break;
        }
        return (sm-2*i);
    }
};