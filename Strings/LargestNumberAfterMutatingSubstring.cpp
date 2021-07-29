//Problem Link:- https://leetcode.com/problems/largest-number-after-mutating-substring/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumNumber(string s, vector<int>& change) {
        const int len = s.length();
        bool flag = false;
        for(int i=0;i<len;i++){
            if (s[i]-'0' < change[s[i]-'0']){
                s[i] = change[s[i]-'0']+'0';
                flag = true;
            }
            else if (s[i]-'0' > change[s[i]-'0']){
                if (flag == true){
                    return s;
                }
                else{
                    continue;
                }
            }
        }
        return s;
    }
};