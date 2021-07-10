//Problem Link:- https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper1(vector<int>& nums){
        stack<int> st;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            while (!st.empty() && st.top() >= nums[i]){
                cnt++;
                st.pop();
                if (cnt > 1){
                    return false;
                }
            }
            st.push(nums[i]);
        }
        if (cnt <= 1){
            return true;   
        }
        return false;
    }
    
    bool helper2(vector<int>& nums){
        stack<int> st;
        int cnt = 0;
        for(int i=nums.size()-1;i>=0;i--){
            while (!st.empty() && nums[i] >= st.top()){
                cnt++;
                st.pop();
                if (cnt > 1){
                    return false;
                }
            }
            st.push(nums[i]);
        }
        if (cnt <= 1){
            return true;
        }
        return false;
    }
    
    bool canBeIncreasing(vector<int>& nums) {
        return helper1(nums) || helper2(nums);
    }
};