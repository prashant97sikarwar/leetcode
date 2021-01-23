//Problem LinK:- https://leetcode.com/problems/stone-game-ii/

/*Alice and Bob continue their games with piles of stones.  There are a number of piles 
arranged in a row, and each pile has a positive integer number of stones piles[i].
The objective of the game is to end with the most stones. Alice and Bob take turns, with Alice
starting first.  Initially, M = 1.On each player's turn, that player can take all the stones 
in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).The game 
continues until all the stones have been taken.Assuming Alice and Bob play optimally, return 
the maximum number of stones Alice can get. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][205];
    int helper(int i, int m,vector<int> & arr){
        if (i >= arr.size())
            return 0;
        if (dp[i][m] != -1)
            return dp[i][m];
        int total = 0;
        int ans = INT_MIN;
        for(int j=0;j<2*m;j++){
            if (i+j < arr.size())
                total += arr[i+j];
            ans = max(ans,total - helper(i+j+1,max(m,j+1),arr));
        }
        return dp[i][m] = ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int sm = 0;
        int diff = helper(0,1,piles);
        for(int i=0;i<piles.size();++i){
            sm += piles[i];
        }
        return (sm + diff) / 2;
    }
};