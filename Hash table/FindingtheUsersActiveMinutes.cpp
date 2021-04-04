//Problem Link:- https://leetcode.com/problems/finding-the-users-active-minutes/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> answer(k,0);
        unordered_map<int,set<int>> ump;
        for(auto rr : logs){
            ump[rr[0]].insert(rr[1]);
        }
        for(auto x : ump){
            auto st = x.second;
            int sz = st.size();
            answer[sz-1]++;
        }
        return answer;
    }
};