//Problem Link:- https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& nums) {
        long long mx = *max_element(nums.begin(),nums.end());
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += (long long) nums[i];
        }
        long long rest = sum - (long long)mx;
        return min({rest * 2 + 1, sum});
    }
};