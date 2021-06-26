//Problem Link:- https://leetcode.com/problems/word-search-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    class Node{
        public:
        bool terminal;
        unordered_map<char,Node*> children;
        char data;
        string word;
        
        Node(char val){
            terminal = false;
            data = val;
        }
    };
public:
    void insert(Node* root,string s){
        Node* cur = root;
        for(char ch : s){
            if (cur->children.count(ch) == 0){
                Node* child = new Node(ch);
                cur->children[ch] = child;
                cur = child;
            }
            else{
                cur = cur->children[ch];
            }
        }
        cur->terminal = true;
        cur->word = s;
    }
    
    void search(int i,int j,int n,int m,vector<vector<char>>& board,Node* cur,vector<string>& res){
        char letter = board[i][j];
        if (board[i][j] == '$' || cur->children.count(letter) == 0){
            return;
        }
        cur = cur->children[letter];
        if (cur->terminal){
            res.push_back(cur->word);
            cur->terminal = false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        if (i > 0){
            search(i-1,j,n,m,board,cur,res);
        }
        if (i < n-1){
            search(i+1,j,n,m,board,cur,res);
        }
        if (j > 0){
            search(i,j-1,n,m,board,cur,res);
        }
        if (j < m-1){
            search(i,j+1,n,m,board,cur,res);
        }
        board[i][j] = temp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node(' ');
        for(string s: words){
            insert(root,s);
        }
        int n = board.size();
        int m = board[0].size();
        vector<string> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                search(i,j,n,m,board,root,res);
            }
        }
        return res;
    }
};