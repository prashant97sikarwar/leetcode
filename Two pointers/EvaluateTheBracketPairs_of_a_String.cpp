//Problem Link:- https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

/* You are given a string s that contains some bracket pairs, with each pair containing a 
non-empty key.You know the values of a wide range of keys. This is represented by a 2D string 
array knowledge where each knowledge[i] = [keyi, valuei] indicates that key keyi has a value 
of valuei.You are tasked to evaluate all of the bracket pairs. When you evaluate a bracket 
pair that contains some key keyi, you will:
1.Replace keyi and the bracket pair with the key's corresponding valuei.
2.If you do not know the value of the key, you will replace keyi and the bracket pair with a 
question mark "?" (without the quotation marks).Each key will appear at most once in your 
knowledge. There will not be any nested brackets in s.Return the resulting string after 
evaluating all of the bracket pairs. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& know) {
        stack<char> st;
        unordered_map<string,string> mp;
        for(auto curr : know){
            mp[curr[0]] = curr[1];
        }
        string ch = "";
        bool flag = 0;
        string ans = "";
        for(int i=0;i<s.length();i++){
            if (s[i] == '('){
                flag = 1;
            }
            else if (flag == 1  && s[i] != ')'){
                ch += s[i];
            }
            else if (s[i] == ')'){
                if (mp.find(ch) != mp.end()){
                    ans += mp[ch];
                }
                else{
                    ans += '?';
                }
                ch = "";
                flag = 0;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};