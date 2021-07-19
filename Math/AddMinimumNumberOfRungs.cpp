//Problem Link:- https://leetcode.com/problems/add-minimum-number-of-rungs/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n = rungs.size();
        int res = 0;
        for(int i=0;i<n;i++){
            int diff = (i == 0 ? rungs[i]-0 : rungs[i] - rungs[i-1]);
            res += ((diff-1) / dist);
        }
        return res;
    }
};