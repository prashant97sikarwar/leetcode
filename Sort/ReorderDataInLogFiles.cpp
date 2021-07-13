//Problem Link:- https://leetcode.com/problems/reorder-data-in-log-files/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   vector<string> reorderLogFiles(vector<string>& logs) {
        auto comp = [](string &a, string &b) {
            string aa = a.substr(a.find(' '));
            string bb = b.substr(b.find(' '));
            
            return aa == bb ? a < b : aa < bb;
        };
        
        vector<string> letters;
        vector<string> digits;
        for (string &str: logs) {
            int i = 0;
            while (i < str.size() && str[i++] != ' ');
            if (isalpha(str[i]))
                letters.push_back(str);
            else
                digits.push_back(str);
        }
        
        sort(letters.begin(), letters.end(), comp);
        
        letters.insert(letters.end(), digits.begin(), digits.end());
        return letters;
    }
};