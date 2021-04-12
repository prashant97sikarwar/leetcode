//Problem Link:- https://leetcode.com/problems/rotate-array/

/*Given an array, rotate the array to the right by k steps, where k is non-negative. 
solve in O(n) time complexity and O(1) space complexity */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0)
            return;
        int n = nums.size();
        k %= n;
        int l = 0;
        int r = n-1;
        while (l <= r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
        l = 0;
        r = k-1;
        while (l <= r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
        l = k;
        r = n-1;
        while (l <= r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
};