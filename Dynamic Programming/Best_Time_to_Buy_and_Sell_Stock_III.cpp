//Problem Link:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

/*Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.*/
#include<bits/stdc++.h>
using namespace std;
int dp[100001][2][3];

int maxProfit(vector<int>& prices) {
        int k = 2; int n = prices.size();
        for(int days = n-1;days >= 0;days--){
            for(int trans = 0;trans <=k;trans++){
                if (days == n-1){
                    dp[days][0][trans] = 0;
                    dp[days][1][trans] = (trans >= 1) ? prices[days] : 0;
                }
                else{
                    dp[days][0][trans] = max(-prices[days] + dp[days+1][1][trans],dp[days+1][0][trans]);
                    dp[days][1][trans] = max(((trans >= 1) ? prices[days] + dp[days+1][0][trans-1] : 0),dp[days+1][1][trans]);
                }
            }
        }
        return dp[0][0][k];
    }

