//Problem Link:- https://leetcode.com/problems/word-ladder/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(string str : wordList){
            s.insert(str);
        }
        if (s.find(endWord) == s.end())
            return 0;
        queue<string> pq;
        pq.push(beginWord);
        int level = 1;
        while (!pq.empty()){
            int n = pq.size();
            while (n--){
                string curr = pq.front();
                pq.pop();
                for(int i=0;i<curr.length();i++){
                    string temp = curr;
                    for(int j=0;j<26;j++){
                        curr[i] = 'a'+j;
                        if (curr == temp)
                            continue;
                        if (curr == endWord)
                            return level+1;
                        if (s.find(curr) != s.end()){
                            pq.push(curr);
                            s.erase(curr);
                        }
                    }
                    curr = temp;
                }
            }
            level++;
        }
        return 0;
    }
};