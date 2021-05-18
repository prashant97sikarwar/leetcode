//Problem Link:- https://leetcode.com/problems/valid-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool point = false;
        bool exp = false;
        bool numbefore = false;
        bool numafter = true;
        
        for(int i=0;i<s.length();i++){
            if ('0' <= s[i] && s[i] <= '9'){
                numbefore =true;
                numafter = true;
            }
            else if (s[i] == '.'){
                if (exp || point){
                    return false;
                }
                point =  true;
            }
            else if (s[i] == 'e' || s[i] == 'E'){
                if (exp || !numbefore){
                    return false;
                }
                exp = true;
                numafter = false;
            }
            else if (s[i] == '-' || s[i] == '+'){
                if(i != 0 && s[i-1] != 'e') {
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return numbefore && numafter;
    }
};