//Problem Link:- https://leetcode.com/problems/next-permutation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        if (i >= 0){
            int j =nums.size() -1;
            while(j > 0 && nums[j] <= nums[i]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
        sort(nums.begin()+i+1,nums.end());
        
    }
};