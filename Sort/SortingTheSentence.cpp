//Problem Link:- https://leetcode.com/problems/sorting-the-sentence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        int n = s.length();
        map<int,string> mp;
        string str;
        for(int i=0;i<n;i++){
            if  (s[i] == ' '){
                continue;
            }
            if (i+1 == n || s[i+1] == ' '){
                int idx = s[i]-'0';
                mp[idx] = str;
                str.clear();
            }
            else{
                str.push_back(s[i]);
            }
        }
        string result = "";
        for(auto x : mp){
            result += x.second;
            result += " ";
        }
        result.erase(result.begin()+result.size()-1);
        return result;
    }
};