//Problem Link:- https://leetcode.com/problems/verifying-an-alien-dictionary/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, int> umap;
    bool cmp(string a, string b){
        int i = 0;
        while(i < min(a.length(), b.length()) and umap[a[i]] == umap[b[i]]){
            i++;
            continue;
        }
        if((a.length() < b.length() and i == min(a.length(), b.length())) || umap[a[i]] < umap[b[i]]){
            return false;
        }
        return true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() <= 1){
            return true;
        }
        for(int i = 0; i < order.length(); i++){
            umap[order[i]] = i;
        }
        for(int i = 1; i < words.size(); i++){
            if(!cmp(words[i], words[i - 1])){
                return false;
            }
        }
        return true;
    }
};