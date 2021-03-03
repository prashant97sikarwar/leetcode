//Problem Link:- https://leetcode.com/problems/longest-nice-substring/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(string str){
        set<char>st;
        for(int i=0;i<str.length();i++){
            st.insert(str[i]);
        }
        for(int i=0;i<str.length();i++){
            if (islower(str[i])){
                if (st.find(str[i]-32) == st.end())
                    return false;
            }
            else{
                if (st.find(str[i]+32) == st.end())
                    return false;
            }
        }
        return true;
    }
    
    string longestNiceSubstring(string s) {
        int n = s.length();
        string ans = "";
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if (helper(s.substr(i,j-i+1))){
                    if (ans.length() < j-i+1)
                        ans = s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};