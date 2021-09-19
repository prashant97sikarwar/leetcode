//Problem link;- https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int result = -1;
public:
    void helper(int i, string& s, string first, string sec){
        if (i == s.length()){
            result = max(result, findSub(first) * findSub(sec));
            return;
        }
        helper(i+1,s,first+s[i],sec);
        helper(i+1,s,first,sec+s[i]);
    }
    
    int findSub(string &s){
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string r = s;
        reverse(r.begin(),r.end());
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if (i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if (s[i-1] == r[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);    
                }
            }
        }
        return dp[n][n];
    }
    
    int maxProduct(string s) {
        helper(0,s,"","");
        return result;
        
    }
};