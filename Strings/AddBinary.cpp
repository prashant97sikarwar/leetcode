//Problem Link:- https://leetcode.com/problems/add-binary/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int n1 = a.length();
        int n2 = b.length();
        if (n1 < n2){
            for(int i=0;i<n2-n1;i++){
                a = '0' + a;
            }
        }
        if (n2 < n1){
            for(int i=0;i<n1-n2;i++){
                b = '0'+b;
            }
        }
        int i = a.length()-1;
        int carry = 0;
        while (i >= 0){
            int sm = (a[i]-'0') + (b[i]-'0') + carry;
            carry = sm / 2;
            char dg = (sm%2)+'0';
            res = dg + res;
            i--;
        }
        if (carry > 0){
            char dg = carry+'0';
            res = dg + res;
        }
        return res;
    }
};