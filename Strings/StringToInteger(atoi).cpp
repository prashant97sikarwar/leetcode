//Problem Link:- https://leetcode.com/problems/string-to-integer-atoi/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int sign = 1;
        if (n == 0){
            return 0;
        }
        int i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }
        if (i == n){
            return 0;
        }
        if (s[i] == '-'){
            sign = -1;
            i++;
        }
        else if (s[i] == '+'){
            sign = 1;
            i++;
        }
        long long sm = 0;
        while (isdigit(s[i])){
            sm = 10*sm + (s[i]-'0');
            i++;
            if (sm > INT_MAX){
                if (sign == -1){
                    return INT_MIN;
                }
                return INT_MAX;
            }
        }
        return sign * sm;
    }
};