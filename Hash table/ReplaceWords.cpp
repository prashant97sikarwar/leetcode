//Problem Link:- https://leetcode.com/problems/replace-words/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<string> s;
    string helper(string str){
        string pf;
        for(int i=0;i<str.length();i++){
            pf.push_back(str[i]);
            if (s.find(pf) != s.end()){
                return pf;
            }
        }
        return str;
    }
    
    string replaceWords(vector<string>& dict, string sent) {
        for (string x : dict){
            s.insert(x);
        }
        string prefix;
        string res = "";
        for(int i=0;i<sent.length();i++){
            if (sent[i] == ' '){
                res += helper(prefix);
                res += ' ';
                prefix.clear();
            }
            else{
                prefix.push_back(sent[i]);
            }
        }
        res += helper(prefix);
        return res;
    }
};