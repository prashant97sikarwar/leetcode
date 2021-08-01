//Problem Link:- https://leetcode.com/problems/reverse-pairs/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long merge(vector<int>&nums, vector<int>& temp,int l, int mid,int r){
        int i = l, j = mid, k = l;
        long long inv = 0;
        for (int i = l;i<mid;i++){
            while (j <= r && nums[i] > 2LL*nums[j]){
                j++;
            }
            inv += j - mid;
        }
        i = l, j = mid;
        while (i <= mid-1 && j <= r){
            if (nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid-1){
            temp[k++] = nums[i++];
        }
        while (j <= r){
            temp[k++] = nums[j++];
        }
        for(int i=l;i<=r;i++){
            nums[i] = temp[i];
        }
        return inv;
    }
    
    long long mergeSort(vector<int>&nums, vector<int>& temp,int l,int r){
        int mid = 0;
        long long inv =  0;
        if (r > l){
            mid = (l+r)/2;
            inv += mergeSort(nums,temp,l,mid);
            inv += mergeSort(nums,temp,mid+1,r);
            inv += merge(nums,temp,l,mid+1,r);
        }
        return inv;
    }
    
    int reversePairs(vector<int>& nums) {
        const int n = nums.size();
        vector<int> temp(n,0);
        return mergeSort(nums,temp,0,n-1);
    }
};