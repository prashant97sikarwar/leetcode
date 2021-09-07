//Problem Link:- https://leetcode.com/problems/add-strings/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        if (num1.length() < num2.length()){
            swap(num1,num2);
        }
        int n = num1.length();
        int m = num2.length();
        
        int i = n-1, j = m-1;
        int carry = 0;
        while (i >= 0 && j >= 0){
            int val = (num1[i] - '0') + (num2[j] - '0') + carry;
            res.push_back((val%10) + '0');
            carry = val / 10;
            i--, j--;
        }
        while (i >= 0){
            int val = carry + (num1[i] - '0');
            res.push_back((val%10) + '0');
            carry = val / 10;
            i--;
        }
        if (carry > 0){
            char ch = carry + '0';
            res.push_back(ch);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};