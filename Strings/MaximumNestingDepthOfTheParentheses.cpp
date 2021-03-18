//Problem Link:- https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

/* Given a valid parenthesis string represented as string s, return the nesting depth of s.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int right = 0;
        int ans = 0;
        int left = 0;
        for(int i=0;i<s.length();i++){
            if (s[i] == '(')
                right++;
            else if(s[i] == ')'){
                ans = max(ans,right-left);
                left++;
            }
        }
        return ans;
    }
};