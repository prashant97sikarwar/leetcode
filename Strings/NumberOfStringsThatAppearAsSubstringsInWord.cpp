//Problem Link;- https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lps[101];
    void preprocess(string &s){
        lps[0] = 0;
        int len = 0,i = 1;
        while (i < s.length()){
            if (s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if (len == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
    }
    
    bool helper(string &word,string& s){
        int i = 0,j = 0;
        while (i < word.length()){
            if (word[i] == s[j]){
                i++;
                j++;
            }
            if (j == s.length()){
                return true;
            }
            else if (i < word.length() && word[i] != s[j]){
                if (j != 0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return false;
    }
    
    int numOfStrings(vector<string>& patterns, string word) {
        int result = 0;
        for(string s : patterns){
            memset(lps,0,sizeof(lps));
            preprocess(s);
            if (helper(word,s)){
                result++;
            }
        }
        return result;
    }
};