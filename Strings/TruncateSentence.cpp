//Problem Link:- https://leetcode.com/problems/truncate-sentence/

/*You are given a sentence s​​​​​​ and an integer k​​​​​​. You want to truncate s​​​​​​ such that it contains 
only the first k​​​​​​ words. Return s​​​​​​ after truncating it. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int sp = 0;
        int idx = -1;
        for(int i=0;i<s.length();i++){
            if (isspace(s[i])){
                sp++;
                if (sp == k){
                    idx = i;
                    break;
                }
            }
            else
                continue;
            
        }
        return s.substr(0,idx);
    }
};