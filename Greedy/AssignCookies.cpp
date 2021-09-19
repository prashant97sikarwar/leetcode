//Problem Link:- https://leetcode.com/problems/assign-cookies/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        stack<int> st;
        int result = 0;
        for(int i=0;i<g.size();i++){
            st.push(g[i]);
        }
        sort(s.rbegin(),s.rend());
        for(int i=0;i<s.size() && !st.empty();i++){
            if (s[i] >= st.top()){
                st.pop();
                result++;
            }
            else{
                while (!st.empty() && s[i] < st.top()){
                    st.pop();
                }
                if (!st.empty()){
                    st.pop();
                    result++;
                }
                else{
                    break;
                }
            }
        }
        return result;
        
    }
};