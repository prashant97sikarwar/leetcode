//Problem Link:- https://leetcode.com/problems/maximum-swap/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums;
        while (num > 0){
            nums.push_back(num%10);
            num /= 10;
        }
        reverse(nums.begin(),nums.end());
        bool flag = false;
        for(int i=0;i<nums.size();i++){
            int mxVal = nums[i];
            int mxIdx = -1;
            for(int j=i+1;j<nums.size();j++){
                if (nums[j] >= mxVal){
                    mxVal = nums[j];
                    mxIdx = j;
                }
            }
            if (mxVal != nums[i]){
                swap(nums[i],nums[mxIdx]);
                break;
            }
        }
        int res = 0;
        for(int i=0;i<nums.size();i++){
            res = 10*res + nums[i];
        }
        return res;
    }
};