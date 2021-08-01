//Problem Link:- https://leetcode.com/problems/top-k-frequent-words/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        const int n = words.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        priority_queue<pair<int,string>> pq;
        for(auto x : mp){
            pq.push({-x.second,x.first});
            if (pq.size() > k){
                pq.pop();
            }
        }
        vector<string> result;
        while (!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};