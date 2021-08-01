//Problem Link:- https://leetcode.com/problems/max-chunks-to-make-sorted/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        const int n = nums.size();
        int mx = 0, res = 0;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            if (mx == i){
                res++;
            }
        }
        return res;
    }
};