//Problem Link:- https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

/* Given an array of integers nums and a positive integer k, find whether it's possible to 
divide this array into k non-empty subsets whose sums are all equal. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool helper(vector<int>& nums,vector<int>& arr,int k, int pos, int index){
        if (index == nums.size()){
            for(int i=0;i<k;i++){
                if (arr[i] != pos)
                    return false;
            }
            return true;
        }
        for(int i=0;i<k;i++){
            if (nums[index] + arr[i] <= pos){
                arr[i] += nums[index];
                if (helper(nums,arr,k,pos,index+1)){
                    return true;
                }
                arr[i] -= nums[index];
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sm = accumulate(nums.begin(),nums.end(),0);
        if (sm % k != 0)
            return false;
        int pos = sm / k;
        vector<int> arr(k,0);
        sort(nums.rbegin(), nums.rend());
        return helper(nums,arr,k,pos,0);
    }
};