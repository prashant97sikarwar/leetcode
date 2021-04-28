//Problem Link:- https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

/*Given the array nums consisting of n positive integers. You computed the sum of all non-empty 
continous subarrays from the array and then sort them in non-decreasing order, creating a new 
array of n * (n + 1) / 2 numbers.Return the sum of the numbers from index left to index right 
(indexed from 1), inclusive, in the new array.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int MOD = 1e9 + 7;
        vector<int> subsm;
        for(int i=0;i<n;i++){
            int temp = 0;
            for(int j=i;j<n;j++){
                temp += nums[j];
                temp %= MOD;
                subsm.push_back(temp);
            }
        }
        sort(subsm.begin(),subsm.end());
        int res = 0;
        for(int i=left-1;i<=right-1;i++){
            res += subsm[i];
            res %= MOD;
        }
        return res;
    }
};