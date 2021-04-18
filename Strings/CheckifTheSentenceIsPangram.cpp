//Problem Link:- https://leetcode.com/problems/check-if-the-sentence-is-pangram/

/*A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a 
pangram, or false otherwise.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string s) {
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if (freq[i] == 0)
                return false;
        }
        return true;
    }
};