//Problem Link:- https://leetcode.com/problems/find-pivot-index/

/*Given an array of integers nums, calculate the pivot index of this array.The pivot index is 
the index where the sum of all the numbers strictly to the left of the index is equal to the 
sum of all the numbers strictly to the index's right. if doesn't exist return -1 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        int sm = prefix[n];
        for(int i=1;i<=n;i++){
            int left = prefix[i-1];
            int right = sm - prefix[i-1]-nums[i-1];
            if (left == right)
                return i-1;
        }
        return -1;
    }
};