//Problem Link:- https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

/* The beauty of a string is the difference in frequencies between the most frequent and least 
frequent characters.Given a string s, return the sum of beauty of all of its substrings. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++){
            vector<int> dp(26,0);
            dp[s[i]-'a']++;
            for(int j=i+1;j<s.length();j++){
                dp[s[j]-'a']++;
                int mx = -1;
                int mn = INT_MAX;
                for(int k=0;k<26;k++){
                    if (dp[k]){
                        mx = max(mx,dp[k]);
                        mn = min(mn,dp[k]);
                    }
                }
                ans += (mx-mn);
            }
        }
        return ans;
    }
};