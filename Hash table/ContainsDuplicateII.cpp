//Problem link:- https://leetcode.com/problems/contains-duplicate-ii/

/*Given an integer array nums and an integer k, return true if there are two distinct indices i 
and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++){
            if (ump.find(nums[i]) != ump.end()){
                if (i - ump[nums[i]] <= k){
                    return true;
                }
                else{
                    ump[nums[i]] = i;
                }
            }
            else{
                ump[nums[i]] = i;
            }
        }
        return false;
    }
};