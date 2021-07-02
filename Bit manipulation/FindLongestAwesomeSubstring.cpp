//Problem Link:- https://leetcode.com/problems/find-longest-awesome-substring/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<long long,int> mp;
        long long mask = 0;
        int res = 0;
        mp[0] = -1;
        for(int i=0;i<s.length();i++){
            mask ^= 1 << (s[i]-'0');
            if (mp.find(mask) != mp.end()){
                res = max(res,i-mp[mask]);
            }
            for(int k=0;k<10;k++){
                long long temp = mask ^ (1 << k);
                if (mp.find(temp) != mp.end()){
                    res = max(res,i-mp[temp]);
                }
            }
            if (mp.find(mask) == mp.end()){
                mp[mask] = i;
            }
        }
        return res;
    }
};