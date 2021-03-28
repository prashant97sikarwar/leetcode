//problem Link:- https://leetcode.com/problems/number-of-different-integers-in-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        int i=0;
        int n = word.length();
        unordered_set<string> s{""};
        for(int j=0;j<n;j++){
            if (isdigit(word[j])){
                i += i < j && word[i] == '0';
            }
            else{
                s.insert(word.substr(i,j-i));
                i = j+1;
            }
        }
        s.insert(word.substr(i));
        return s.size()-1;
    }
    

};