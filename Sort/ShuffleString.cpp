//Problem Link:- https://leetcode.com/problems/shuffle-string/

/*Given a string s and an integer array indices of the same length.The string s will be shuffled 
such that the character at the ith position moves to indices[i] in the shuffled string.Return the 
shuffled string.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<char,int> x, pair<char,int> y){
        return x.second < y.second;
    }
    
    string restoreString(string s, vector<int>& indices) {
        vector<pair<char,int>> vct;
        for(int i=0;i<s.length();i++){
            vct.push_back({s[i],indices[i]});
        }
        sort(vct.begin(),vct.end(),cmp);
        string res = "";
        for(int i=0;i<s.length();i++){
            res += vct[i].first;
        }
        return res;
    }
};