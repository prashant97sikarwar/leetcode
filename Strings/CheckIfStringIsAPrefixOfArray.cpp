//Problem Link:- https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string res = "";
        for(int k=0;k<words.size();k++){
            res += words[k];
            if (res == s){
                return true;
            }
        }
        return false;
    }
};