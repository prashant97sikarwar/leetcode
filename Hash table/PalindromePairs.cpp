//Problem Link:- https://leetcode.com/problems/palindrome-pairs/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ispal(string s){
        int l = 0, r = s.length()-1;
        while (l <= r){
            if (s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]] = i;
        }
        for(int i=0;i<words.size();i++){
            string word = words[i];
            reverse(word.begin(),word.end());
            if (mp.find(word) != mp.end() && mp[word] != i){
                res.push_back({i,mp[word]});
            }
        }
        if (mp.find("") != mp.end()){
            int idx = mp[""];
            for(int i=0;i<words.size();i++){
                if (ispal(words[i]) && idx != i){
                    res.push_back({idx,i});
                    res.push_back({i,idx});
                }
            }
        }
        for(int i=0;i<words.size();i++){
            string cur = words[i];
            for(int cut=1;cut<cur.length();cut++){
                string left = cur.substr(0,cut);
                string right = cur.substr(cut);
                if (ispal(left)){
                    reverse(right.begin(),right.end());
                    if (mp.find(right) != mp.end() && mp[right] != i){
                        res.push_back({mp[right],i});
                    }
                }
                if (ispal(right)){
                    reverse(left.begin(),left.end());
                    if (mp.find(left) != mp.end() && mp[left] != i){
                        res.push_back({i,mp[left]});
                    }
                }
            }
        }
        return res;
    }
};