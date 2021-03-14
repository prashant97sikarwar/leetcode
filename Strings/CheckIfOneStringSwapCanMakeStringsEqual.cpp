//Problem Link:- https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

/* You are given two strings s1 and s2 of equal length. A string swap is an operation where 
you choose two indices in a string (not necessarily different) and swap the characters at 
these indices.Return true if it is possible to make both strings equal by performing at most 
one string swap on exactly one of the strings. Otherwise, return false. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<pair<char,char>> lst;
        for(int i=0;i<s1.length();i++){
            if (s1[i] != s2[i]){
                lst.push_back({s1[i],s2[i]});
                if (lst.size() > 2)
                    return false;
            }
        }
        if (lst.size() == 0)
            return true;
        if (lst.size()!=2)
            return false;
        char a1 = lst[0].first;
        char a2 = lst[0].second;
        char b1 = lst[1].first;
        char b2 =  lst[1].second;
        if (a1 == b2 && a2 == b1)
            return true;
        return false;
    }
};
