//Problem Link:- https://leetcode.com/problems/permutation-sequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i=1;i<=n;i++){
            s.push_back(i+'0');
        }
        while (--k){
            next_permutation(s.begin(),s.end());
        }
        return s;
    }
};