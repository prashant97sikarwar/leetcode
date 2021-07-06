//Problem Link:- https://leetcode.com/problems/accounts-merge/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,string> emailname;
        map<string,vector<string>> graph;
        for(auto acc : accounts){
            string name = acc[0];
            for(int i=1;i<acc.size();i++){
                graph[acc[1]].push_back(acc[i]);
                graph[acc[i]].push_back(acc[1]);
                emailname[acc[i]] = name;
            }
        }
        unordered_set<string> seen;
        vector<vector<string>> result;
        for(auto x : graph){
            string email = x.first;
            if (seen.find(email) == seen.end()){
                seen.insert(email);
                stack<string> st;
                st.push(email);
                vector<string> component;
                while (!st.empty()){
                    auto node = st.top();
                    st.pop();
                    component.push_back(node);
                    for(auto nie : graph[node]){
                        if (seen.find(nie) == seen.end()){
                            seen.insert(nie);
                            st.push(nie);
                        }
                    }
                }
                string name = emailname[email];
                sort(component.begin(),component.end());
                component.insert(component.begin(),name);
                result.push_back(component);
            }
        }
        return result;
    }
};