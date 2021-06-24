//Problem Link:- https://leetcode.com/problems/map-sum-pairs/

#include<bits/stdc++.h>
using namespace std;

class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string,int> score;
    unordered_map<string,int> mp;
    MapSum() {
        score.clear();
        mp.clear();
    }
    
    void insert(string key, int val) {
        int delta = val - (mp.find(key) == mp.end() ? 0 : mp[key]);
        mp[key] = val;
        string prefix;
        for(char ch : key){
            prefix.push_back(ch);
            score[prefix] += delta;
            
        }
    }
    
    int sum(string prefix) {
        return score[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */