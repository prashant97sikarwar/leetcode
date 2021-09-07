//Problem Link:- https://leetcode.com/problems/split-array-largest-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(int key,vector<int>& nums,int m, int n){
        int cnt = 0, sm = 0;
        for(int i=0;i<n;i++){
            sm += nums[i];
            if (sm > key){
                cnt++;
                sm = nums[i];
            }
        }
        cnt++;
        if (cnt <= m){
            return true;
        }
        return false;
    }
    
    int splitArray(vector<int>& nums, int m) {
        const int n = nums.size();
        int left = *max_element(nums.begin(),nums.end());
        int right = accumulate(nums.begin(),nums.end(),0);
        
        int result = INT_MAX;
        
        while (left <= right){
            int mid = left + (right-left)/2;
            if (helper(mid,nums,m,n)){
                result = min(result,mid);
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return result;
    }
};