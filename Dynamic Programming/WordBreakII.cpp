//Problem Link:- https://leetcode.com/problems/word-break-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,vector<string>> dp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        if (dp.find(s) != dp.end()){
            return dp[s];
        }
        for(string w : wordDict){
            if (s.substr(0,w.length()) == w){
                if (w.length() == s.length()){
                    result.push_back(w);
                }
                else{
                    vector<string> temp = wordBreak(s.substr(w.length()), wordDict);
                    for(string x : temp){
                        result.push_back(w + " " + x);
                    }
                }
            }
        }
        dp[s] = result;
        return result;
    }
};