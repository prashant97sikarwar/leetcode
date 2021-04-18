//Problem Link;- https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=1;i<n;i++){
            if (nums[i] > nums[i-1]){
                continue;
            }
            else{
                res += (nums[i-1]+1-nums[i]);
                nums[i] = nums[i-1]+1;
            }
        }
        return res;
    }
};