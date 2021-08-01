//Problem Link:- https://leetcode.com/problems/remove-duplicate-letters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int len = s.length();
        vector<int> freq(26,0);
        vector<bool> mark(26,0);
        for(int i=0;i<len;i++){
            freq[s[i]-'a']++;
        }
        stack<char> st;
        for(int i=0;i<len;i++){
            freq[s[i]-'a']--;
            if (mark[s[i]-'a']){
                continue;
            }
            while (!st.empty() && s[i] < st.top() && freq[st.top()-'a'] > 0){
                mark[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            mark[s[i]-'a'] = true;
        }
        string result;
        while (!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};