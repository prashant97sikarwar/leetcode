//Problem Link:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

/* You are given an integer array prices where prices[i] is the price of a given stock 
on the ith day.Design an algorithm to find the maximum profit. You may complete at most 
k transactions. */

#include <bits/stdc++.h>
using namespace std;

int dp[31][2][11];
int solve(int i, bool own, int k, vector<int> A,int n){
    if (i >= n+1 || k == 0){
        return 0;
    }
    if (dp[i][own][k] != -1)
        return dp[i][own][k];
    if (own){
        int op1 = A[i-1] + solve(i+1,0,k-1,A,n);
        int op2 = solve(i+1,1,k,A,n);
        return dp[i][own][k] = max(op1,op2);
    }
    else{
        int op1 = -A[i-1] + solve(i+1,1,k,A,n);
        int op2 = solve(i+1,0,k,A,n);
        return dp[i][own][k] = max(op1,op2);
    }
}

int traderProfit(int k, int n, vector <int> A) {
    memset(dp,-1,sizeof dp);
    return solve(1,0,k,A,n);
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
            cin >> arr[arr_i];
        }
        int result = traderProfit(k, n, arr);
        cout << result << endl;
    }
    return 0;
}


