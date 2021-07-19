//Problem Link:- https://leetcode.com/problems/maximum-number-of-words-you-can-type/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(string str,unordered_set<char>& broke){
        for(int i=0;i<str.length();i++){
            if (broke.count(str[i])){
                return false;
            }
        }
        return true;
    }
    
    int canBeTypedWords(string s, string broken) {
        unordered_set<char> broke;
        for(int i=0;i<broken.length();i++){
            broke.insert(broken[i]);
        }
        string str;
        int res = 0;
        for(int i=0;i<s.length();i++){
            if (s[i] == ' '){
                if (helper(str,broke)){
                    res++;
                }
                str.clear();
            }
            else{
                str.push_back(s[i]);
            }
        }
        if (helper(str,broke)){
            res++;
        }
        return res;
    }
};