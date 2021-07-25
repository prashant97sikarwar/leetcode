//Problem Link:- https://leetcode.com/problems/last-substring-in-lexicographical-order/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        const int len = s.length();
        int max_idx = 0;
        char mx = s[0];
        for(int i=1;i<len;i++){
            if (s[i] > mx){
                mx = s[i];
                max_idx = i;
            }
            else if (s[i] == mx){
                int it = 1;
                while (s[max_idx+it] == s[i+it] && max_idx+it < i){
                    it++;
                }
                if (s[i+it] > s[max_idx+it]){
                    max_idx = i;
                }
                i = i+it-1;
            }
        }
        return s.substr(max_idx);
    }
};