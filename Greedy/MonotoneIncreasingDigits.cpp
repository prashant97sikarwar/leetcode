//Problem Link:- https://leetcode.com/problems/monotone-increasing-digits/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> nums;
        int num = n;
        int digits = 0;
        while (num > 0){
            digits++;
            nums.push_back(num%10);
            num /= 10;
        }
        int idx = 0;
        bool flag = false;
        reverse(nums.begin(),nums.end());
        for(int i=0;i<digits-1;i++){
            if (nums[i+1] < nums[i]){
                idx = i;
                flag = true;
                break;    
            }
        }
        if (!flag){
            return n;
        }
        if (nums[idx] == 1){
            int result = 0;
            for(int i=0;i<digits-1;i++){
                result = result*10 + 9;
            }
            return result;
        }
        
        int vic = (nums[idx]-1);
        int val = nums[idx];
        while (idx >= 0 && nums[idx] == val){
            nums[idx] = vic;
            idx--;
        }
        for(int i=idx+2;i<nums.size();i++){
            nums[i] = 9;
        }
        int result = 0;
        for(int i=0;i<nums.size();i++){
            result = result*10 + nums[i];
        }
        return result;
    }
};