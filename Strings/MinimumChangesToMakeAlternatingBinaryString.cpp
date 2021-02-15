//Problem Link:- https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

/* You are given a string s consisting only of the characters '0' and '1'. In one operation, 
you can change any '0' to '1' or vice versa.The string is called alternating if no two adjacent 
characters are equal.Return the minimum number of operations needed to make s alternating. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        string first;
        string sec;
        for(int i=0;i<s.length();i++){
            if (i % 2 == 0){
                first.push_back('0');
                sec.push_back('1');
            }
            else{
                first.push_back('1');
                sec.push_back('0');
            }
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<s.length();i++){
            if (s[i] != first[i])
                cnt1++;
            if (s[i] != sec[i])
                cnt2++;
        }
        return min(cnt1,cnt2);
        
    }
};

 