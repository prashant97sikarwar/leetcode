//Problem Link:- https://leetcode.com/problems/maximum-score-after-splitting-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        if (s.length() == 0){
            return 0;
        }
        int n = s.length();
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0] = (s[0] == '0') ? 1 : 0;
        right[n-1] = (s[n-1] == '1') ? 1 : 0;
        for(int i=1;i<n;i++){
            left[i] = (s[i] == '0') ? 1+left[i-1] : left[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i] = (s[i]-'0') + right[i+1];
        }
        int res = 0;
        for(int i=0;i<n-1;i++){
            res = max(res,left[i] + right[i+1]);
        }
        return res;
    }
};