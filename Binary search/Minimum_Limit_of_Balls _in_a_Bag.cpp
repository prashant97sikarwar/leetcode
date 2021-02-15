//Problem Link:- https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

/* You are given an integer array nums where the ith bag contains nums[i] balls. You are also 
given an integer maxOperations.You can perform the following operation at most maxOperations 
times:Take any bag of balls and divide it into two new bags with a positive number of balls. 
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after 
the operations.Return the minimum possible penalty after performing the operations. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(vector<int>& nums,int balls, int maxOperations){
        int opr = 0;
        for(int i=0;i<nums.size();i++){
            if (nums[i] <= balls)
                continue;
            else{
                int x = (nums[i] / balls);
                if (nums[i] % balls == 0)
                    opr += x -1;
                else
                    opr += x;
            }
        }
        if (opr <= maxOperations)
            return true;
        else
            return false;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int mx = -1;
        int n = nums.size();
        for(int i=0;i<n;i++)
            mx = max(mx,nums[i]);
        int left = 1;
        int right = mx;
        int res = right;
        while (left <= right){
            int mid = (left+right)/2;
            if (helper(nums,mid,maxOperations)){
                if (mid < res){
                    res = mid;
                }
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return res;
    }
};