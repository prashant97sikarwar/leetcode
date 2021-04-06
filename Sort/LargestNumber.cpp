//Problem:- https://leetcode.com/problems/largest-number/

/*Given a list of non-negative integers nums, arrange them such that they form the largest 
number.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(string s1,string s2){
        return s1 + s2 > s2 + s1;
    }

    string largestNumber(vector<int>& A) {
        int n = A.size();
        vector<string> s;
        for(int i=0;i<n;i++){
            s.push_back(to_string(A[i]));
        }
        sort(s.begin(),s.end(),cmp);
        string res = "";
        for(int i=0;i<n;i++){
            for(int j=0;j<s[i].length();j++){
                res += s[i][j];
            }
        }
        return (res[0]-'0' == 0) ? "0" : res;
    }
};