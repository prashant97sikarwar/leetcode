//Problem Link:- https://leetcode.com/problems/word-break/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[n] = 1;
        unordered_set<string> mp;
        for(auto x : wordDict){
            mp.insert(x);
        }
        for(int i=n-1;i>=0;i--){
            string word;
            for(int j=i;j<n;j++){
                word.push_back(s[j]);
                if (word.length() > 20){
                    break;
                }
                if (mp.find(word) != mp.end()){
                    if (dp[j+1] ==1){
                        dp[i] = 1;
                    }
                }
            }
        }
        return dp[0];
    }
};