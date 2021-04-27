//Problem Link:- https://leetcode.com/problems/find-all-duplicates-in-an-array/

/*Given an integer array nums of length n where all the integers of nums are in the range [1, n] 
and each integer appears once or twice, return an array of all the integers that appears twice.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(int i=0;i<n;i++){
            int idx = abs(nums[i])-1;
            if (nums[idx] < 0){
                result.push_back(idx+1);
            }
            else{
                nums[idx] = -nums[idx];
            }
        }
        return result;
    }
};