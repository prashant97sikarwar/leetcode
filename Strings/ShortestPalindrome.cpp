//Problem Link:- https://leetcode.com/problems/shortest-palindrome/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.length() == 0 || s.length() == 1){
            return s;
        }
        string str = s;
        string initialString = s;
        reverse(s.begin(),s.end());
        str.push_back('$');
        str += s;
        int n = str.length();
        vector<int> lps(n,0);
        int i = 1, len = 0;
        while (i < n){
            if (str[i] == str[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if (len != 0){
                    len = lps[len - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int tot = initialString.length() - lps.back();
        string suff = initialString.substr(initialString.length()-tot);
        reverse(suff.begin(),suff.end());
        return suff + initialString;
    }
};