//Problem Link:- https://leetcode.com/contest/weekly-contest-228/problems/count-number-of-homogenous-substrings/

/* Given a string s, return the number of homogenous substrings of s. Since the answer may be 
too large, return it modulo 109 + 7.A string is homogenous if all the characters of the string
are the same.A substring is a contiguous sequence of characters within a string.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        long long MOD = 1e9 + 7;
        long long n = s.length();
        if (n == 1)
            return 1;
        long long cnt = 1;
        long long res = 0;
        for(int i=0;i<n-1;i++){
            if (s[i] == s[i+1])
                cnt++;
            else{
                res += (cnt * (cnt+1)) /2;
                res %= MOD;
                cnt = 1;
            }
        }
        res += (cnt * (cnt+1)) /2;
        res %= MOD;
        return res;
    }
};