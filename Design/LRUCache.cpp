//problem Link:- https://leetcode.com/problems/lru-cache/

#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    list<pair<int,int>> dq;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    int sz;
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key){
        if (mp.find(key) == mp.end()){
            return -1;
        }
        else{
            int res = (*mp[key]).second;
            dq.erase(mp[key]);
            dq.push_front({key,res});
            return res;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()){
            if (dq.size() == sz){
                int last_key = dq.back().first;
                dq.pop_back();
                mp.erase(last_key);
            }
        }
        else{
            dq.erase(mp[key]);
        }
        dq.push_front({key,value});
        mp[key] = dq.begin();
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */