//Problem Link:- https://leetcode.com/problems/repeated-dna-sequences/

/*Given a string s that represents a DNA sequence, return all the 10-letter-long sequences 
(substrings) that occur more than once in a DNA molecule. You may return the answer in any 
order. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10)
            return {};
        map<string,int> ump;
        for(int i=0;i<s.length()-9;i++){
            string ch = s.substr(i,10);
            ump[ch]++;
        }
        vector<string> result;
        for (auto str : ump){
            if (str.second > 1){
                result.push_back(str.first);
            }
        }
        return result;
    }
};