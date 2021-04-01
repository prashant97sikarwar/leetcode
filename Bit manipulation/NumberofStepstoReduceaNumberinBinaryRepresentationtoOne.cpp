//Problem Link:- https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

/* Given a number s in their binary representation. Return the number of steps to reduce it 
to 1 under the following rules:
1.If the current number is even, you have to divide it by 2.
2.If the current number is odd, you have to add 1 to it. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(string &s){
        int carry = 0;
        char ch = (s[s.length()-1] - '0' + 1)%2 + '0';
        s[s.length()-1] = ch;
        carry = 1;
        for(int i=s.length()-2;i>=0;i--){
            char ch = (s[i] - '0' + carry)%2 + '0';
            carry = (s[i] - '0' + carry) / 2;
            s[i] = ch;
        }
        if (carry > 0){
            char fl = carry + '0';
            s = fl + s;
        }
    }
    
    int numSteps(string s) {
        int ans = 0;
        while (s.length() > 1){
            if (s[s.length()-1] == '0'){
                ans++;
                s.erase(s.begin()+s.length()-1);
            }
            else{
                ans++;
                helper(s);
            }
        }
        return ans;
    }
};