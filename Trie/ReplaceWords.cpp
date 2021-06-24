//Problem link:- https://leetcode.com/problems/replace-words/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    class Node{
        public:
        char data;
        unordered_map<char,Node*> children;
        bool terminal;
        
        Node(char val){
            data = val;
            terminal = false;
        }
    };
    Node* root = new Node(' ');
public:
    void insert(string prefix){
        Node* cur = root;
        for( char ch : prefix){
            if (cur->children.count(ch)){
                cur = cur->children[ch];
            }
            else{
                Node* child = new Node(ch);
                cur->children[ch] = child;
                cur = child;
            }
        }
        cur->terminal = true;
    }
        
    string helper(string prefix){
        Node* cur = root;
        string ans;
        for( char ch : prefix){
            if (cur->children.count(ch)){
                cur = cur->children[ch];
                ans.push_back(ch);
                if (cur->terminal == true){
                    return ans;
                }
            }
            else{
                return prefix;
            }
        }
        return prefix;
    }
        
    string replaceWords(vector<string>& dict, string s) {
        for(string x : dict){
            insert(x);
        }
        string prefix;
        string res = "";
        for(int i=0;i<s.length();i++){
            if (s[i] ==' '){
                res += helper(prefix);
                res  += " ";
                prefix.clear();
            }
            else{
                prefix.push_back(s[i]);
            }
        }
        res += helper(prefix);
        return res;
    }
};