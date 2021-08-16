//Problem Link:- https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        const int n = s.length();
        int idx = n-1;
        while (s[idx] != '['){
            idx--;
        }
        int result = 0;
        int co = 0,cc = 0;
        for(int i=0;i<n;i++){
            if (i >= idx){
                break;
            }
            if (s[i] == '['){
                co++;
            }
            else{
                cc++;
                if (cc > co){
                    result++;
                    swap(s[i],s[idx]);
                    cc--;
                    co++;
                    while (idx >= 0 && s[idx] != '['){
                        idx--;
                    }
                }
            }
        }
        return result;
    }
};

