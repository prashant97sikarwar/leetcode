//Problem Link:- https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include<bits/stdc++.h>
using namespace std;

class WordDictionary {
    private:
    class Node{
        public:
            char value;
            bool terminal;
            unordered_map<char,Node*> children;
        
        Node(int val){
            value = val;
            terminal = false;
        }
        
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node(' ');
    }
    
    void addWord(string word) {
        Node* cur = root;
        for(char ch : word){
            if (cur->children.count(ch)){
                cur = cur->children[ch];
            }
            else{
                Node* child = new Node(ch);
                cur->children[ch] =  child;
                cur = child;
            }
        }
        cur->terminal = true;
    }
    bool helper(string word,int idx,Node* cur){
        if (idx >= word.length()){
            return cur->terminal;
        }
        if (word[idx] == '.'){
            for(auto child : cur->children){
                if (helper(word,idx+1,child.second)){
                    return true;
                }
            }
        }
        else{
            if (cur->children.count(word[idx])){
                return helper(word,idx+1,cur->children[word[idx]]);
            }
        }
        return false;
    }
    bool search(string word) {
        return helper(word,0,root);
    }
};
