//Problem Link:- https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(string &s,int i,long long prev){
        long long num = 0;
        for(int j=i;num < 1e+10 && j < s.length()-(i == 0 ? 1 : 0);++j){
            num = num*10 + (s[j]-'0');
            if ((i == 0 || prev-1 == num) && helper(s,j+1,num)){
                return true;
            }
        }
        return i == s.length();
    }
    
    bool splitString(string s) {
        return helper(s,0,0);
    }
};