//Problem Link:- https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string helper(string str,int k){
        if (k == 0){
            return str;
        }
        int total = 0;
        for(int i=0;i<str.length();i++){
            total += (str[i]-'0');
        }
        string s = to_string(total);
        return helper(s,k-1);
    }
    
    int getLucky(string s, int k) {
        const int n = s.length();
        string str = "";
        for(int i=0;i<n;i++){
            str += to_string(s[i]-'a'+1);
        }
        string res = helper(str,k);
        int ans = 0;
        int f = 1;
        for(int i=res.length()-1;i>=0;i--){
            ans += (res[i]-'0')*f;
            f *= 10;
        }
        return ans;
    }
};