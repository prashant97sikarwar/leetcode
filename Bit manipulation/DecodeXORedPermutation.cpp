//Problem Link:- https://leetcode.com/problems/decode-xored-permutation/

/* There is an integer array perm that is a permutation of the first n positive integers, where 
n is always odd.It was encoded into another integer array encoded of length n - 1, such that 
encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].Given 
the encoded array, return the original array perm. It is guaranteed that the answer exists and is
unique. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        vector<int> ans;
        int n = encoded.size() + 1;
        int first = 0;
        for(int i=1;i<=n;i++){
            first = first ^ i;
        }
        for(int i=1;i<n-1;i+=2){
            first ^= encoded[i];
        }
        ans.push_back(first);
        for(int i=0;i<n-1;i++){
            int next = ans.back() ^ encoded[i];
            ans.push_back(next);
        }
        return ans;
    }
};