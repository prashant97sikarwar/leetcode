//Problem Link:- https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26,0);
        int n = words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].length();j++){
                freq[words[i][j]-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if (freq[i] > 0 && freq[i] % n != 0){
                return false;
            }
        }
        return true;
    }
};