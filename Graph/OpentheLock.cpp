//Problem Link:- https://leetcode.com/problems/open-the-lock/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> helper(string s){
        vector<string> result;
        for(int j = 0 ; j < 4 ; j++) {
            string t = s;
            int n1 = t[j] - '0' + 1;
            int n2 = t[j] - '0' - 1;

            if(n2 < 0) 
                n2 = n2 + 10;
            n1 = n1%10;
            n2 = n2%10;
            t[j] = n1 + '0';
            result.push_back(t);
            t[j] = n2 + '0';
            result.push_back(t);
        }
        return result;
    }
    
    int openLock(vector<string>& deadends, string target) {
        if ("0000" == target)
            return 0;
        unordered_set<string> dict(deadends.begin(),deadends.end());
        if (dict.find("0000") != dict.end())
            return -1;
        queue<string> pq;
        pq.push("0000");
        unordered_map<string,int>dist;
        dist["0000"] = 0;
        while (!pq.empty()){
            string node = pq.front();
            int d = 1 + dist[node];
            pq.pop();
            vector<string> nxt = helper(node);
            for(auto str : nxt){
                if (dict.find(str) == dict.end() && dist.find(str) == dist.end()){
                    if (str == target){
                        return d;
                    }
                dist[str] = d;
                pq.push(str);
                }
            }
        }
        return -1;
        
    }
};