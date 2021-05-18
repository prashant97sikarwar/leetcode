//Problem Link:- https://leetcode.com/problems/integer-to-roman/

#include<bits/stdc++.h>
using namespace  std;

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> mp = {{1,"I"}, 
                               {5,"V"}, 
                               {10,"X"}, 
                               {50,"L"}, 
                               {100,"C"}, 
                               {500,"D"}, 
                               {1000,"M"}, 
                               {4,"IV"}, 
                               {9,"IX"}, 
                               {40,"XL"},
                               {90,"XC"},
                               {400,"CD"},
                               {900,"CM"}};   
        string ans;
        while(num > 0){
            auto it = --mp.upper_bound(num);
            num -= (it->first);
            ans += (it->second);
        }
        return ans;      
    }
};