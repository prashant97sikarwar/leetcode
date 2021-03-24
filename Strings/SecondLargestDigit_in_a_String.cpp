//Problem Link:- https://leetcode.com/problems/second-largest-digit-in-a-string/

/* Given an alphanumeric string s, return the second largest numerical digit that appears 
in s, or -1 if it does not exist. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int mx = -1;
        int smx = -1;
        for(int i=0;i<s.length();i++){
            if (isdigit(s[i])){
                if (s[i]-'0' > mx){
                    smx = mx;
                    mx = s[i]-'0';
                }
                else if (s[i]-'0' > smx && s[i]-'0' != mx){
                    smx = s[i]-'0';
                }
            }
            else
                continue;
        }
        return (smx >= 0) ? smx : -1;
    }
};