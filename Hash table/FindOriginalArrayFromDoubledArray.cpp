//Problem Link:- https://leetcode.com/problems/find-original-array-from-doubled-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        const int n = changed.size();
        if (n%2 == 1){
            return {};
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[changed[i]]++;
        }
        vector<int> keys;
        for(auto x : mp){
            keys.push_back(x.first);
        }
        vector<int> result;
        sort(keys.begin(),keys.end());
        for(int x : keys){
            if (mp[x] > mp[2*x]){
                return {};
            }
            for(int i=0;i<mp[x];i++,mp[2*x]--){
                result.push_back(x);
            }
        }
        return result;
    }
};