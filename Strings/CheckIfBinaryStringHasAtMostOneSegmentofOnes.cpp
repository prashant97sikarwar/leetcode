//Problem Link:- https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/

/* Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one 
contiguous segment of ones. Otherwise, return false. */ 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        int i =0;
        while (s[i] == '1' && i < n){
            i++;
        }
        if (i == n)
            return true;
        while (i < n){
            if (s[i] == '1')
                return false;
            i++;
        }
        return true;
    }
};