//Problem Link:- https://leetcode.com/problems/number-of-matching-subsequences/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     bool matchString(string a,string b){
        int n1 = a.size(), n2 = b.size(), i = 0, j = 0;
        while(i < n1 && j < n2){
            if(a[i] == b[j]) j++;
         i++;
        }
        return j == n2;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        int ans = 0;
    
         for(auto& w:words){
            if(mp.find(w) != mp.end()) ans += mp[w];
            else {
                mp[w] = matchString(s,w);
                ans += mp[w];
            }
        }
        return ans;
    }
};