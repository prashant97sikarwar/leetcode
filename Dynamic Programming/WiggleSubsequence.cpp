//Problem Link:- https://leetcode.com/problems/wiggle-subsequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int n = nums.size();
        int up, down;
        
        up = down = 1;
        
        for(int i=1;i<n;i++){
            if (nums[i] > nums[i-1]){
                up = 1 + down;
            }
            else if (nums[i] < nums[i-1]){
                down = 1 + up;
            }
        }
        return max(up,down);
        
    }
};