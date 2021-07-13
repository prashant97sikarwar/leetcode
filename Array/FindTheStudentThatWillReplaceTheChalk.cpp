//Problem Link:- https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long> nums(n);
        nums[0] = chalk[0];
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i-1] + (1LL)*chalk[i];
        }
        long long sm = nums[nums.size()-1];
        long long turn = k / sm;
        long long left = k - (turn * nums[nums.size()-1]);
        int res = upper_bound(nums.begin(),nums.end(),left) - nums.begin();
        return res;
    }
};