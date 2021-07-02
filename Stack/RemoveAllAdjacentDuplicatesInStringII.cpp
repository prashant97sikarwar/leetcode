//Problem Link:- https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.length();i++){
            if (st.empty()){
                st.push({s[i],1});
            }
            else{
                auto node = st.top();
                char ch = node.first;
                int cnt = node.second;
                if (s[i] == ch){
                    if (cnt+1 == k){
                        while (!st.empty() && st.top().first == s[i]){
                            st.pop();
                        }   
                    }
                    else{
                        st.push({s[i],cnt+1});
                    }
                }
                else{
                    st.push({s[i],1});
                }
            }
        }
        string res;
        while (!st.empty()){
            res.push_back(st.top().first);
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};