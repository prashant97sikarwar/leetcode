//Problem Link:- https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        const int n = s.length();
        const int m = t.length();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int result = 0;
        for(int i=0;i<n;i++){
            if (freq[t[i]-'a'] <= 0){
                result++;
            }
            else{
                freq[t[i]-'a']--;
            }
        }
        return result;
    }
};