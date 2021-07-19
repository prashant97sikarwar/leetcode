//Problem Link:- https://leetcode.com/problems/pancake-sorting/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findindex(vector<int>&nums,int num){
        for(int i=0;i<nums.size();i++){
            if (nums[i] == num){
                return i;
            }
        }
        return -1;
    }
    
    void helper(vector<int>&arr,int idx){
        int l = 0,r=idx;
        while (l <= r){
            swap(arr[l],arr[r]);
            l++,r--;
        }
    }
    
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        int idx;
        for(int i=n;i>0;i--){
            if (arr[i-1] != i){
                idx = findindex(arr,i);
                result.push_back(idx+1);
                helper(arr,idx);
                result.push_back(i);
                helper(arr,i-1);
            }
        }
        return result;
    }
};