//Problem Link:- https://leetcode.com/problems/word-ladder-ii/

/* A transformation sequence from word beginWord to word endWord using a dictionary wordList is 
a sequence of words such that:
1.The first word in the sequence is beginWord.
2.The last word in the sequence is endWord.
3.Only one letter is different between each adjacent pair of words in the sequence.
4.Every word in the sequence is in wordList.
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest 
transformation sequences from beginWord to endWord, or an empty list if no such sequence exists.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<string>>& result,vector<string> path,string beginWord, string endWord,unordered_map<string,unordered_set<string>> &adj){
        path.push_back(beginWord);
        if (beginWord == endWord){
            result.push_back(path);
            path.pop_back();
            return;
        }
        for(auto word:adj[beginWord]){
            dfs(result,path,word,endWord,adj);
        }
        path.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,unordered_set<string>> adj;
        unordered_set<string> dict(wordList.begin(),wordList.end());
        
        queue<string> pq;
        pq.push(beginWord);
        unordered_map<string,int> visited;
        visited[beginWord] = 0;
        while (!pq.empty()){
            int sz = pq.size();
            while(sz--){
                string curr = pq.front();
                pq.pop();
                for(int i=0;i<curr.length();i++){
                    string temp = curr;
                    for(int j=0;j<26;j++){
                        curr[i] = 'a'+j;
                        if (curr == temp)
                            continue;
                        if (dict.count(curr) > 0){
                            if (visited.count(curr) == 0){
                                visited[curr] = 1 + visited[temp];
                                pq.push(curr);
                                adj[temp].insert(curr);
                            }
                            else if (visited[curr] == 1 + visited[temp]){
                                adj[temp].insert(curr);
                            }
                        }
                    }
                    curr = temp;
                }
            }
        }
        vector<vector<string>> result;
        vector<string> path;
        dfs(result,path,beginWord,endWord,adj);
        return result;
    }
};