//Problem Link:- https://leetcode.com/problems/maximum-xor-for-each-query/

/*You are given a sorted array nums of n non-negative integers and an integer maximumBit. You want 
to perform the following query n times:
1. Find a non-negative integer k < 2maximumBit such that nums[0] XOR nums[1] XOR ... XOR 
    nums[nums.length-1] XOR k is maximized. k is the answer to the ith query.
2.Remove the last element from the current array nums.
Return an array answer, where answer[i] is the answer to the ith query.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int bits) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i] ^= nums[i-1];
        }
        vector<int> result;
        int mask = 0;
        for(int i=0;i<bits;i++){
            mask += (1 << i);
        }
        for(int i=n-1;i>=0;i--){
            result.push_back(mask ^ nums[i]);
        }
        return result;
    }
};