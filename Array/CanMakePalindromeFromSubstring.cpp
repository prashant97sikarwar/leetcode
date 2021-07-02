//Problem Link:- https://leetcode.com/problems/can-make-palindrome-from-substring/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<vector<int>> prefix(n,vector<int> (26,0));
        for(int i=0;i<n;i++){
            prefix[i][s[i]-'a']++;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<26;j++){
                prefix[i][j] += prefix[i-1][j];
            }
        }
        vector<bool> result;
        for(auto &q : queries){
            int x = q[0];
            int y = q[1];
            int op = q[2];
            int odd = 0;
            if (x == 0){
                for(int i=0;i<26;i++){
                    if (prefix[y][i] % 2 == 1){
                        odd++;
                    }
                }
                
            }
            else{
                for(int i=0;i<26;i++){
                    int val = prefix[y][i] - prefix[x-1][i];
                    if (val%2 == 1){
                        odd++;
                    }
                }
            }
            if (op >= odd/2){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
        return result;
    }
};