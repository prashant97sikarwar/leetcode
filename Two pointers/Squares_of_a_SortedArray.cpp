//Problem Link:- https://leetcode.com/problems/squares-of-a-sorted-array/

/*Given an integer array nums sorted in non-decreasing order, return an array of the squares 
of each number sorted in non-decreasing order.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        int left = 0;
        int right = n-1;
        while (left <= right){
            if (nums[left] * nums[left] < nums[right]*nums[right]){
                result.push_back(nums[right]*nums[right]);
                right--;
            }
            else{
                result.push_back(nums[left] * nums[left]);
                left++;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};