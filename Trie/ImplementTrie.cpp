//Problem Link:- https://leetcode.com/problems/implement-trie-prefix-tree/

#include<bits/stdc++.h>
using namespace std;

class Trie {
    /** Initialize your data structure here. */
    private:
    class Node{
        public:
        char value;
        bool terminal;
        unordered_map<char,Node*> children;
        
        Node(char data){
            value = data;
            terminal = false;
        }
    };
    Node* root; 
    public:
    Trie() {
        root = new Node(' ');
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        for(char ch : word){
            if (cur->children.count(ch)){
                cur = cur->children[ch];
            }
            else{
                Node* child = new Node(ch);
                cur->children[ch] = child;
                cur = child;
            }
        }
        cur->terminal =  true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        for(char ch : word){
            if (cur->children.count(ch) == 0){
                return false;
            }
            else{
                cur = cur->children[ch];
            }
        }
        return cur->terminal;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        for(char ch : prefix){
            if (cur->children.count(ch) == 0){
                return false;
            }
            else{
                cur = cur->children[ch];
            }
        }
        return true;
    }
};
