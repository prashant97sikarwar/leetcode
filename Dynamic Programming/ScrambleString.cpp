//Problwm Link:- https://leetcode.com/problems/scramble-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()){
            return false;
        }
        if (s1.compare(s2) == 0){
            return true;
        }
        if (s1.length() <= 1){
            return false;
        }
        string key = s1 + " " + s2;
        if (mp.find(key) != mp.end()){
            return mp[key];
        }
        int n = s1.length();
        for(int i=1;i<n;i++){
            bool op1 = isScramble(s1.substr(0,i),s2.substr(n-i)) && isScramble(s1.substr(i),s2.substr(0,n-i));
            bool op2 = isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i));
            if (op1 || op2){
                return true;
                break;
            }
        }
        return mp[key] = false;
    }
};