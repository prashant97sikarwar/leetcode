//Problem Link:- https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> mp;
        unordered_map<char, int> letters;
        int ans = 0;
        
        for(int len = minSize; len <= maxSize; ++len) {
            string str;
            
            for(int i=0; i<s.size(); i++) {
                letters[s[i]]++;
                str += s[i];
                
                if(i >= len) {
                    letters[s[i-len]]--;
                    if(letters[s[i-len]] == 0) letters.erase(s[i-len]);
                    str.erase(str.begin());
                }
                
                if(str.size() == len && letters.size() <= maxLetters) {
                    mp[str]++;
                }
            }   
        }
        
        for(auto x : mp) {
            ans = max(ans, x.second);
        }
        return ans;
    }
};