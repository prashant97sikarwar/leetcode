//Problem Link:- https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[105][105];
    
    int helper(vector<int> &cuts, int i,int j){
        if (j-i <= 1){
            return 0;
        }
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 1e9;
        for(int k=i+1;k<j;k++){
            int temp = helper(cuts,i,k) + helper(cuts,k,j) + (cuts[j] - cuts[i]);
            ans = min(ans,temp);
        }
        return dp[i][j] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.insert(cuts.end(),n);
        return helper(cuts,0,cuts.size()-1);
    }
};