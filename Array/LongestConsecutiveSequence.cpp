//Problem Link:- https://leetcode.com/problems/longest-consecutive-sequence/

/* Given an unsorted array of integers nums, return the length of the longest consecutive 
elements sequence.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if (nums.size() == 0)
            return 0;
        int res = 1;
        int cur = 1;
        for(int i=1;i<nums.size();i++){
            if (nums[i] != nums[i-1]){
                if (nums[i] == nums[i-1] + 1){
                    cur++;
                }
                else{
                    res = max(res,cur);
                    cur = 1;
                }
            }
        }
        return max(res,cur);
    }
};