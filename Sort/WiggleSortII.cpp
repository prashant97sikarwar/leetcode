//Problem Link:- https://leetcode.com/problems/wiggle-sort-ii/

/*Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        int index = 1;
        int k = n -1;
        while (index < n){
            nums[index] = temp[k--];
            index+=2;
        }
        index = 0;
        while (index < n){
            nums[index] = temp[k--];
            index+=2;
        }
        
    }
};