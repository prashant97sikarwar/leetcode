//Problem Link:- https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        for(int i=0;i<s.length();i++){
            if(i+part.length()-1 < s.length()&&s.substr(i,part.length())==part){
                s.erase(i,part.length());
                i=-1;
            }
        }
        return s;
    }
};