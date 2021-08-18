//Problem Link:- https://leetcode.com/problems/cherry-pickup/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int inf = -1e9;
    int cherry_picker(vector<vector<int>>& grid,vector<vector<vector<int>>>&dp,int r1,int c1,int c2,int n){
        int r2 = r1 + c1 - c2;
        if(r1>=n || r2>=n || c1>=n || c2>=n|| grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return INT_MIN;
        }
        if(dp[r1][c1][c2]!=-1){
            return dp[r1][c1][c2];   
        }
        if(r1==n-1 && c1 == n-1){
            return grid[r1][c1];   
        }
        int ans = grid[r1][c1];
        if(r1!=r2){
            ans += grid[r2][c2];   
        }
        int temp = max({cherry_picker(grid,dp,r1,c1+1,c2+1,n),cherry_picker(grid,dp,r1+1,c1,c2,n),
                       cherry_picker(grid,dp,r1,c1+1,c2,n),cherry_picker(grid,dp,r1+1,c1,c2+1,n)});
        ans += temp;
        dp[r1][c1][c2] = ans;
        return ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,cherry_picker(grid,dp,0,0,0,n));
    }
};