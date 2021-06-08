//Problem Link:- https://leetcode.com/problems/bulb-switcher-iv/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string target) {
        int k = 1, res = 0;
        for(int i=0;i<target.length();i++){
            if (target[i]-'0' == k){
                res++;
                if (k == 0){
                    k = 1;
                }
                else{
                    k = 0;
                }
            }
        }
        return res;
    }
};