//Problem Link:- https://leetcode.com/problems/number-of-wonderful-substrings/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> nums(1028,0);
        nums[0] = 1;
        long long mask = 0, res = 0;
        for(char &ch : word){
            mask ^= 1 << (ch-'a');
            res += nums[mask];
            for(int i=0;i<10;i++){
                res += nums[mask ^ (1 << i)];
            }
            nums[mask]++;
        }
        return res;
    }
};