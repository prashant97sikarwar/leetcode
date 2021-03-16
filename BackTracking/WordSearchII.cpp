//Problem Link:- https://leetcode.com/problems/word-search-ii/

/* Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells 
are horizontally or vertically neighboring. The same letter cell may not be used more than once 
in a word. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board,int i,int j,int count,string letter,vector<vector<bool>>& visited){
        if (count == letter.length())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != letter[count] || visited[i][j] == true)
            return false;
        char temp = board[i][j];
        visited[i][j] = true;
        bool flag = dfs(board,i+1,j,count+1,letter,visited) || dfs(board,i-1,j,count+1,letter,visited) || dfs(board,i,j+1,count+1,letter,visited) || dfs(board,i,j-1,count+1,letter,visited);
        visited[i][j] = false;
        return flag;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<string> result;
        unordered_map<char,vector<pair<int,int>>> ump;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch = board[i][j];
                ump[ch].push_back({i,j});
            }
        }
        for(int i=0;i<words.size();i++){
            string letter = words[i];
            for(auto x:ump[letter[0]]){
                if (dfs(board,x.first,x.second,0,letter,visited)){
                    result.push_back(letter);
                    break;
                }
        
            }
        }
        return result;
    }
};