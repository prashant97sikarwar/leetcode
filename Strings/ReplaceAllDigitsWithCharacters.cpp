//Problem Link:- https://leetcode.com/problems/replace-all-digits-with-characters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        int n = s.length();
        string res = "";
        for(int i=0;i<n;i+=2){
            if (i+1 < n){
                res += s[i];
                res += (s[i]+(s[i+1]-'0'));
            }
        }
        if (n&1){
            res += s[n-1];
        }
        return res;
    }
};