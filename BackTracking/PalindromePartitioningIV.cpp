//Problem Link:- https://leetcode.com/problems/palindrome-partitioning-iv/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPartitioning(string s) {
        int dp[2001][2001] = {0};
        int n = s.length();
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        for(int l=2;l<=n-1;l++){
            for(int i=0;i<n-l+1;i++){
                int end = i+l-1;
                if (s[i] == s[end] && (l <= 2 || dp[i+1][end-1] == 1)){
                    dp[i][end] = 1;
                }
            }
        }
        
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<n;j++){
                if (dp[0][i-1] == 1 && dp[i][j-1] == 1 && dp[j][n-1] == 1){
                    return true;
                }
            }
        }
        return false;
    }
};