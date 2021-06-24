//Problem Link:- https://leetcode.com/problems/map-sum-pairs/

#include<bits/stdc++.h>
using namespace std;

class MapSum {
    private:
    class Node{
        public:
        map<char,Node*> children;
        bool terminal;
        int val;
        char data;
        
        Node(char x){
            terminal = false;
            val = 0;
            data = x;
        }
    };
    Node* root;
public:
    unordered_map<string,int> mp;
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node(' ');
    }
    void helper(int delta, string key){
        Node* cur = root;
        for(char ch : key){
            if (cur->children.count(ch) == 0){
                cur->children[ch] = new Node(ch);
            }
            cur = cur->children[ch];
            cur->val += delta;
        }
        cur->terminal = true;
    }
    
    void insert(string key, int val) {
        int delta = val - (mp.find(key) == mp.end() ? 0 : mp[key]);
        mp[key] = val;
        helper(delta, key);
    }
    
    int sum(string prefix) {
        Node* cur = root;
        for(char ch : prefix){
            if (cur->children.count(ch) == 0){
                return 0;
            }
            cur = cur->children[ch];
        }
        return cur->val;
    }
};
