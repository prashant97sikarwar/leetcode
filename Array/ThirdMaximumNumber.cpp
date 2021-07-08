//Problem Link:- https://leetcode.com/problems/third-maximum-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long int first = LONG_MIN;
        long int sec = LONG_MIN;
        long int third = LONG_MIN;
        for(int i=0;i<nums.size();i++){
            if (nums[i] > first){
                third = sec;
                sec = first;
                first = nums[i];
            }
            else if (nums[i] < first && nums[i] > sec){
                third = sec;
                sec = nums[i];
            }
            else  if (nums[i] < first && nums[i] < sec && nums[i] > third){
                third = nums[i];
            }
        }
        return (third == LONG_MIN ? first : third);
    }
};