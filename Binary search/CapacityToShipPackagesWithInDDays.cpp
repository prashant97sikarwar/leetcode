//Problem Link:- https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

/* conveyor belt has packages that must be shipped from one port to another within D days.The ith 
package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages 
on the conveyor beltReturn the least weight capacity of the ship that will result in all the packages
on the conveyor belt being shipped within D days.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(int wt,vector<int>&nums,int D){
        int tot = 0;
        int day = 1;
        for(int i=0;i<nums.size();i++){
            tot += nums[i];
            if (tot > wt){
                day++;
                tot = nums[i];
                if (day > D){
                    return false;
                }
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& nums, int D) {
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        while (l < r){
            int mid = l + (r-l)/2;
            if (helper(mid,nums,D)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};